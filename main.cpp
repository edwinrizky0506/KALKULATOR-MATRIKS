#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10;

// Menampilkan matriks
void tampilkan(double A[][MAX], int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << setw(10) << fixed << setprecision(2) << A[i][j];
        }
        cout << endl;
    }
}

// Input matriks
void inputMatriks(double A[][MAX], int baris, int kolom, char nama) {
    cout << "\nMasukkan elemen Matriks " << nama << ":\n";

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << nama << "[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> A[i][j];
        }
    }
}

// Penjumlahan
void penjumlahan(double A[][MAX], double B[][MAX],
                 double C[][MAX], int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Pengurangan
void pengurangan(double A[][MAX], double B[][MAX],
                 double C[][MAX], int baris, int kolom) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Perkalian
void perkalian(double A[][MAX], double B[][MAX],
               double C[][MAX],
               int barisA, int kolomA, int kolomB) {

    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomB; j++) {
            C[i][j] = 0;

            for (int k = 0; k < kolomA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Transpose
void transpose(double A[][MAX], double T[][MAX],
               int baris, int kolom) {

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            T[j][i] = A[i][j];
        }
    }
}

// Determinan matriks 2x2
double determinan2x2(double A[][MAX]) {
    return (A[0][0] * A[1][1]) -
           (A[0][1] * A[1][0]);
}

// Invers matriks 2x2
bool invers2x2(double A[][MAX], double I[][MAX]) {

    double det = determinan2x2(A);

    if (det == 0) {
        return false;
    }

    I[0][0] = A[1][1] / det;
    I[0][1] = -A[0][1] / det;
    I[1][0] = -A[1][0] / det;
    I[1][1] = A[0][0] / det;

    return true;
}

int main() {

    double A[MAX][MAX] = {};
    double B[MAX][MAX] = {};
    double C[MAX][MAX] = {};
    double T[MAX][MAX] = {};

    int pilihan;

    do {

        cout << "\n====================================\n";
        cout << "       KALKULATOR MATRIKS C++\n";
        cout << "====================================\n";
        cout << "1. Penjumlahan Matriks\n";
        cout << "2. Pengurangan Matriks\n";
        cout << "3. Perkalian Matriks\n";
        cout << "4. Transpose Matriks\n";
        cout << "5. Determinan Matriks 2x2\n";
        cout << "6. Invers Matriks 2x2\n";
        cout << "0. Keluar\n";
        cout << "====================================\n";

        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {

        case 1: {
            int baris, kolom;

            cout << "\nJumlah baris: ";
            cin >> baris;

            cout << "Jumlah kolom: ";
            cin >> kolom;

            inputMatriks(A, baris, kolom, 'A');
            inputMatriks(B, baris, kolom, 'B');

            penjumlahan(A, B, C, baris, kolom);

            cout << "\nHasil A + B:\n";
            tampilkan(C, baris, kolom);

            break;
        }

        case 2: {
            int baris, kolom;

            cout << "\nJumlah baris: ";
            cin >> baris;

            cout << "Jumlah kolom: ";
            cin >> kolom;

            inputMatriks(A, baris, kolom, 'A');
            inputMatriks(B, baris, kolom, 'B');

            pengurangan(A, B, C, baris, kolom);

            cout << "\nHasil A - B:\n";
            tampilkan(C, baris, kolom);

            break;
        }

        case 3: {
            int barisA, kolomA;
            int barisB, kolomB;

            cout << "\n=== Matriks A ===\n";

            cout << "Jumlah baris A: ";
            cin >> barisA;

            cout << "Jumlah kolom A: ";
            cin >> kolomA;

            cout << "\n=== Matriks B ===\n";

            cout << "Jumlah baris B: ";
            cin >> barisB;

            cout << "Jumlah kolom B: ";
            cin >> kolomB;

            if (kolomA != barisB) {
                cout << "\nERROR!\n";
                cout << "Jumlah kolom A harus sama dengan jumlah baris B.\n";
                break;
            }

            inputMatriks(A, barisA, kolomA, 'A');
            inputMatriks(B, barisB, kolomB, 'B');

            perkalian(A, B, C,
                      barisA, kolomA, kolomB);

            cout << "\nHasil A x B:\n";

            tampilkan(C, barisA, kolomB);

            break;
        }

        case 4: {
            int baris, kolom;

            cout << "\nJumlah baris: ";
            cin >> baris;

            cout << "Jumlah kolom: ";
            cin >> kolom;

            inputMatriks(A, baris, kolom, 'A');

            transpose(A, T, baris, kolom);

            cout << "\nTranspose Matriks A:\n";

            tampilkan(T, kolom, baris);

            break;
        }

        case 5: {

            cout << "\n=== DETERMINAN 2x2 ===\n";

            inputMatriks(A, 2, 2, 'A');

            double det = determinan2x2(A);

            cout << "\nDeterminan A = "
                 << fixed << setprecision(2)
                 << det << endl;

            break;
        }

        case 6: {

            cout << "\n=== INVERS 2x2 ===\n";

            inputMatriks(A, 2, 2, 'A');

            if (invers2x2(A, C)) {

                cout << "\nMatriks A:\n";
                tampilkan(A, 2, 2);

                cout << "\nInvers A:\n";
                tampilkan(C, 2, 2);

            } else {

                cout << "\nMatriks tidak memiliki invers.\n";
                cout << "Determinan = 0.\n";
            }

            break;
        }

        case 0:
            cout << "\nProgram selesai.\n";
            break;

        default:
            cout << "\nPilihan tidak tersedia!\n";
        }

    } while (pilihan != 0);

    return 0;
}