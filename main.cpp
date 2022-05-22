#include <iostream>
using namespace std;

class Personel{
	public:
		int perNo, perMaas;
        string perIs, perSoyis, perBolum;
    Personel *adres;
}*start;

void personelEkleme(int per_num, int per_maas, string isim, string soyisim, string calbolum){
	if (start == NULL){
		start = new Personel();
		start -> perNo = per_num;
        start -> perIs = isim;
        start -> perSoyis = soyisim;
        start -> perBolum = calbolum;
        start -> perMaas = per_maas;
		start -> adres = NULL;
	}
	else{
        Personel *temp = start;
        while(temp->adres != NULL){
            temp = temp->adres;
        }
        temp->adres=new Personel();
        temp->adres->perNo=per_num;
        temp->adres->perMaas=per_maas;
        temp->adres->adres=NULL;
	}
}

void Cikarma(int per_num){
    Personel *temp=start;
    Personel *prev=NULL;
    while (temp != NULL && temp->perNo != per_num){
        prev=temp;
        temp=temp->adres;
    }
    if (temp){
        if (prev){
            prev->adres=temp->adres;
            delete temp;
            cout << "Isten cikarildi!" << endl;
        }
        else{
            start=temp->adres;
            delete temp;
            cout << "Isten cikarildi!" << endl;
        }
    }
    else{
        cout << "Personal numarasi YANLIS!";
    }
}

double sumPers(Personel *sum_pers){
    int sum=0;
    while (sum_pers != NULL){
        sum_pers = sum_pers -> adres;
        sum++;
    }
    return sum;
}

void perGoster(Personel *per){
    while (per != NULL){
        cout << "Personelin Numarasi: " << per->perNo << endl;
        cout << "Personal ismi: " << per->perIs << endl;
        cout << "Personal soyismi: " << per->perSoyis << endl;
        cout << "Personelin Maas'i: " << per->perMaas << endl;
        per = per->adres;
    }
}

double persMaasToplam(Personel *per_maas){
    double sum=0;
    while (per_maas != NULL){
        ///cout << "Personelin Maas'i: " << per_maas->perMaas << endl;
        sum += per_maas->perMaas;
        per_maas = per_maas->adres;
    }
    return sum;
}

void Maas(Personel *maas){
    double max=0, min=2147483647;
    while (maas != NULL){
        if (max < maas->perMaas){
            max = maas->perMaas;
        }
        if (min > maas->perMaas){
            min = maas->perMaas;
        }
        maas = maas->adres;
    }
    cout << "En cok maas: " << max << endl;
    cout << "En az maas: " << min << endl;
}


int main(){
	int menu, per_sayi, per_num, per_maas;
    string isim, soyisim, per_bolum;

	while(true){
		cout << endl << "Secenekler:" << endl;
		cout << endl;
		cout << "1.Personel eklemek.\n2.Personel isten cikarmak.\n3.Toplam maas raporu.\n4.Toplam calisanlar sayisi.\n5.En cok ve En az maas alan.\n6.Personalleri Goster.\n7.Sistem cikisi.\n";
		cout << endl << "Lutfen bir secenek giriniz:";
        cin >> menu;

		switch(menu){
			case 1:
                cout << "Personal ismini girin:";
                cin >> isim;
                cout << "Personal soyisimini girin:";
                cin >> soyisim;
                cout << "Personalin calistigi bolum:";
                cin >> per_bolum;
                cout << "Personel numarasi:";
                cin >> per_num;
                cout << "Personel maasi:";
                cin >> per_maas;
                personelEkleme(per_num, per_maas, isim, soyisim,  per_bolum);
            break;
            case 2:
                cout << "Cikarmak istediginiz personel numarasini girin: ";
                cin >> per_num;
                Cikarma(per_num);
                break;
            case 3:
                cout  << "Personallerin toplam maas'i: " << persMaasToplam(start) << endl;
                break;
            case 4:
                cout << endl << "Toplam calisanlar sayisi: ";
                cout << sumPers(start);
                break;
            case 5:
                Maas(start);
                break;
            case 6:
                cout << endl << "Personaller:" << endl;
                perGoster(start);
                break;
            case 7:
                exit(true);
                break;
		}
	}
}