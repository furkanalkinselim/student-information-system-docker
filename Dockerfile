FROM ubuntu:22.04 AS builder
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libpqxx-dev \
    git \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY . .
RUN mkdir -p build && cd build && \
    cmake .. && \
    make
FROM ubuntu:22.04
RUN apt-get update && apt-get install -y \
    libpqxx-dev \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY --from=builder /app/build/sis-app .
CMD ["./sis-app"]
