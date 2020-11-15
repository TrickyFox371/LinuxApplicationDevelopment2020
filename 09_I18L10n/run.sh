autoreconf -fisv
./configure
make
LANGUAGE=ru_RU PO_LOCAL=1 ./guess
