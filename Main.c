#include <stdio.h>
#include <stdlib.h>
#include "linked.h"
#include "halaman.h"

int main() {
    List mahasiswa;
    CreateList(&mahasiswa);
    loadFromFile(&mahasiswa);
    welcomeScreen();
    dashboard(&mahasiswa);
    saveToFile(mahasiswa);
    return 0;
}



