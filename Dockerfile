FROM ubuntu:22.04

# Kutuphaneleri yukle
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
    g++ \
    libpqxx-dev \
    libpq-dev \
    make \
    && rm -rf /var/lib/apt/lists/*

# Calisma klasoru
WORKDIR /app

# Dosyalari kopyala
COPY . .

# ONEMLI DUZELTME: Once eski dosyayi sil (clean), sonra sifirdan derle!
RUN make clean && make

# Calistir
CMD ["./okul_sistemi"]
