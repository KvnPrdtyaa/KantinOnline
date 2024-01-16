#include <iostream>
#include <vector>

using namespace std;

class Jajanan {
public:
    string nama;
    int harga;

    Jajanan(string _nama, int _harga) : nama(_nama), harga(_harga) {}
};

class TransaksiKantin {
private:
    vector<Jajanan> daftarJajanan;
    vector<int> jumlahBeli;

public:
    void tambahJajanan(Jajanan jajanan) {
        daftarJajanan.push_back(jajanan);
        jumlahBeli.push_back(0);
    }

    void beliJajanan(int index, int jumlah) {
        jumlahBeli[index] += jumlah;
    }

    void tampilkanDaftarJajanan() {
        cout << "==== Daftar Jajanan ====" << endl;
        for (size_t i = 0; i < daftarJajanan.size(); ++i) {
            cout << i + 1 << ". " << daftarJajanan[i].nama << " (Harga per item: " << daftarJajanan[i].harga << " Rupiah)" << endl;
        }
    }

    void tampilkanTransaksi() {
        cout << "==== Transaksi Kantin Online ====" << endl;
        for (size_t i = 0; i < daftarJajanan.size(); ++i) {
            cout << daftarJajanan[i].nama << " - Jumlah: " << jumlahBeli[i] << endl;
        }
    }

    int hitungTotalPembayaran() {
        int total = 0;
        for (size_t i = 0; i < daftarJajanan.size(); ++i) {
            total += daftarJajanan[i].harga * jumlahBeli[i];
        }
        return total;
    }

    int hitungKembalian(int uangDibayar) {
        int totalPembayaran = hitungTotalPembayaran();
        return uangDibayar - totalPembayaran;
    }

    size_t getJumlahJajanan() const {
        return daftarJajanan.size();
    }
};

int main() {
    TransaksiKantin transaksi;

    transaksi.tambahJajanan(Jajanan("Keripik", 5000));
    transaksi.tambahJajanan(Jajanan("Minuman", 3000));
    transaksi.tambahJajanan(Jajanan("Cokelat", 7000));
    transaksi.tambahJajanan(Jajanan("Gorengan", 2000));

    int pilihan;
    int jumlah;

    do {
        transaksi.tampilkanDaftarJajanan();

        cout << "Pilih jajanan yang ingin dibeli (ketik 0 untuk melakukan pembayaran): ";
        cin >> pilihan;

        if (pilihan > 0 && pilihan <= transaksi.getJumlahJajanan()) {
        
            cout << "Masukkan jumlah jajanan yang ingin dibeli: ";
            cin >> jumlah;

            transaksi.beliJajanan(pilihan - 1, jumlah);
            cout << "Jajanan berhasil ditambahkan ke keranjang." << endl;
        } else if (pilihan != 0) {
            cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }

    } while (pilihan != 0);

    if (transaksi.getJumlahJajanan() > 0) {
        transaksi.tampilkanTransaksi();

        int totalPembayaran = transaksi.hitungTotalPembayaran();
        cout << "Total Pembayaran: " << totalPembayaran << " Rupiah" << endl;

        int uangDibayar;
        cout << "Masukkan jumlah uang yang dibayarkan: ";
        cin >> uangDibayar;

        while (uangDibayar < totalPembayaran) {
            cout << "Uang yang dibayarkan kurang. Silakan masukkan jumlah uang yang mencukupi: ";
            cin >> uangDibayar;
        }

        int kembalian = transaksi.hitungKembalian(uangDibayar);
        cout << "Kembalian: " << kembalian << " Rupiah" << endl;
    } else {
        cout << "Tidak ada pembelian. Program keluar." << endl;
    }

    return 0;
}
