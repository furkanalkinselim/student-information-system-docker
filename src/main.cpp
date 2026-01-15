#include <iostream>
#include <pqxx/pqxx>
#include <string>
#include <cstdlib>

using namespace std;
using namespace pqxx;

// Veritabani baglanti ayari (Docker ve Local uyumlu)
string get_connection_string() {
    // Docker'da "db" ismini, localde "127.0.0.1" kullanir
    string db_host = getenv("DB_HOST") ? getenv("DB_HOST") : "127.0.0.1";
    
    // DUZELTME: "hostaddr=" yerine "host=" kullandik. Boylece "db" ismini taniyacak.
    return "dbname=testdb user=postgres password=12345 host=" + db_host + " port=5432";
}

void tabloyuHazirla() {
    try {
        connection C(get_connection_string());
        if (C.is_open()) {
            work islem(C);
            string sql = "CREATE TABLE IF NOT EXISTS OGRENCILER (" \
                         "ID SERIAL PRIMARY KEY," \
                         "AD TEXT NOT NULL," \
                         "SOYAD TEXT NOT NULL," \
                         "NO INT NOT NULL );";
            islem.exec(sql);
            islem.commit();
        }
    } catch (const std::exception &e) {
        // Tablo zaten varsa veya baglanti hatasi olursa buraya duser
        // Ilk acilista hata vermemesi icin sessizce gecebiliriz veya ekrana basabiliriz.
        // cout << "Tablo kontrol: " << e.what() << endl; 
    }
}

void ogrenciEkle() {
    string ad, soyad;
    int no;
    cout << "Ogrenci Adi: "; cin >> ad;
    cout << "Ogrenci Soyadi: "; cin >> soyad;
    cout << "Ogrenci No: "; cin >> no;

    try {
        connection C(get_connection_string());
        work islem(C);
        string sql = "INSERT INTO OGRENCILER (AD, SOYAD, NO) VALUES ('" + ad + "', '" + soyad + "', " + to_string(no) + ")";
        islem.exec(sql);
        islem.commit();
        cout << "\n>>> Kayit basariyla eklendi! <<<\n" << endl;
    } catch (const std::exception &e) {
        cout << "Ekleme hatasi: " << e.what() << endl;
    }
}

void listele() {
    try {
        connection C(get_connection_string());
        work islem(C);
        result sonuc = islem.exec("SELECT * FROM OGRENCILER ORDER BY ID ASC");
        
        cout << "\n---------------- OGRENCI LISTESI ----------------" << endl;
        if (sonuc.empty()) {
            cout << "Listede hic ogrenci yok." << endl;
        } else {
            for (auto row : sonuc) {
                cout << "No: " << row["NO"].c_str() 
                     << " | Ad: " << row["AD"].c_str() 
                     << " | Soyad: " << row["SOYAD"].c_str() << endl;
            }
        }
        cout << "-------------------------------------------------\n" << endl;
    } catch (const std::exception &e) {
        cout << "Listeleme hatasi: " << e.what() << endl;
    }
}

void ogrenciSil() {
    int silinecekNo;
    cout << "Silinecek No: "; cin >> silinecekNo;
    try {
        connection C(get_connection_string());
        work islem(C);
        string sql = "DELETE FROM OGRENCILER WHERE NO = " + to_string(silinecekNo);
        result r = islem.exec(sql);
        islem.commit();
        if(r.affected_rows() > 0) cout << "\n>>> Ogrenci silindi. <<<\n" << endl;
        else cout << "\n>>> Ogrenci bulunamadi. <<<\n" << endl;
    } catch (const std::exception &e) {
        cout << "Silme hatasi: " << e.what() << endl;
    }
}

void ogrenciGuncelle() {
    int hedefNo, yeniNo;
    string yeniAd, yeniSoyad;
    cout << "Degisecek Ogrenci No: "; cin >> hedefNo;
    cout << "YENI Ad: "; cin >> yeniAd;
    cout << "YENI Soyad: "; cin >> yeniSoyad;
    cout << "YENI Numara: "; cin >> yeniNo;

    try {
        connection C(get_connection_string());
        work islem(C);
        string sql = "UPDATE OGRENCILER SET AD = '" + yeniAd + "', SOYAD = '" + yeniSoyad + "', NO = " + to_string(yeniNo) + 
                     " WHERE NO = " + to_string(hedefNo);
        result r = islem.exec(sql);
        islem.commit();
        if(r.affected_rows() > 0) cout << "\n>>> Bilgiler guncellendi! <<<\n" << endl;
        else cout << "\n>>> Ogrenci bulunamadi. <<<\n" << endl;
    } catch (const std::exception &e) {
        cout << "Guncelleme hatasi: " << e.what() << endl;
    }
}

int main() {
    tabloyuHazirla();
    int secim;
    while(true) {
        cout << "1. Ekle\n2. Listele\n3. Sil\n4. Guncelle\n0. Cikis\nSecim: ";
        cin >> secim;
        if(secim == 0) break;
        switch(secim) {
            case 1: ogrenciEkle(); break;
            case 2: listele(); break;
            case 3: ogrenciSil(); break;
            case 4: ogrenciGuncelle(); break;
            default: cout << "Hatali secim!" << endl;
        }
    }
    return 0;
}
