FROM ubuntu:22.04


ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
    g++ \
    libpqxx-dev \
    libpq-dev \
    make \
    && rm -rf /var/lib/apt/lists/*


WORKDIR /app


COPY . .


RUN make clean && make


CMD ["./okul_sistemi"]
