FROM dabbertorres/sfml-ubuntu-16.04

# build
RUN apt-get update && apt-get install -y \
curl unzip wget
RUN apt-get --no-install-recommends install -y ca-certificates
RUN echo "nameserver: 127.0.0.53" >> /etc/resolv.conf
WORKDIR /build
COPY install-csfml.sh .
RUN chmod 755 /build/install-csfml.sh
RUN /build/install-csfml.sh
# cleanup
WORKDIR /
RUN rm -r /build
COPY . ./home