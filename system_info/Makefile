.PHONY: build

CC = gcc
SOURCE_FOLDER = src
DISTRIBUTION_FOLDER = dist
TARGET = SystemInfo

run: build
	./${DISTRIBUTION_FOLDER}/${TARGET}

build: clean
	mkdir -p ${DISTRIBUTION_FOLDER}
	$(CC) -o ${DISTRIBUTION_FOLDER}/${TARGET} ${SOURCE_FOLDER}/*.c

clean:
	rm -rf ${DISTRIBUTION_FOLDER}/
