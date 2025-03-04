FROM ghcr.io/open-education-hub/vmcheker-next-base-image/base-container:latest

RUN apt update -y && apt upgrade -y
RUN apt install cabal-install -y
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends tzdata
RUN apt install openjdk-17-jdk-headless -y

COPY ./checker ${CHECKER_DATA_DIRECTORY}
