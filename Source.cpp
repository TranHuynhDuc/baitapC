#include <conio.h>
#include <stdio.h>


struct SV
{
	char hoten[50];
	float toan, ly, hoa;
	char mssv[50];
};
void nhapmang(SV *dsSV, int &n)
{
	int m = 0;
	printf("nhap n  ");
	scanf_s("%d", &m);
	int limit = m + n;
	for (int i = n; i < limit; i++)
	{
		fseek(stdin, 0, SEEK_END);
		printf("nhap ho ten ");
		gets_s(dsSV[i].hoten);
		printf("nhap mssv ");
		gets_s(dsSV[i].mssv);
		printf("nhap diem Toan "); scanf_s("%f", &dsSV[i].toan);
		printf("nhap diem Ly "); scanf_s("%f", &dsSV[i].ly);
		printf("nhap diem Hoa "); scanf_s("%f", &dsSV[i].hoa);
		n++;
	}

}
void xuatmang(SV*dssv, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nsinh vien : %s", dssv[i].hoten);
		printf("\nMSSV : %s", dssv[i].mssv);
		printf("\ndiem toan : %.2f", dssv[i].toan);
		printf("\ndiem ly : %.2f", dssv[i].ly);
		printf("\ndiem hoa : %.2f", dssv[i].hoa);
		printf("\n------------------------------------\n");
	}
}
void nhapdulieutuFILE(SV*dssv, int &n)
{
	n = 0;
	//delete dssv;
	//dssv = new SV[1000];
	FILE *fin;
	fopen_s(&fin, "data.bin", "rb");
	if (fin != NULL)
		while (!feof(fin))
			if (fread(dssv++, sizeof(SV), 1, fin))
				n++;
	printf("Loaded");
	fclose(fin);
}

void luuFile(SV *dssv, int n) {
	FILE *fout;
	fopen_s(&fout, "data.bin", "wb");
	fwrite(dssv, sizeof(SV), n, fout);
	printf("Saved");
	fclose(fout);
}

void main()
{
	int n = 0;
	int chon;
	SV *dssv = new SV[100];
	bool exit = false;
	do
	{
		printf("chon chuc nang :");
		printf("\n1/ nhap thong tin tu ban phim");
		printf("\n2/ nhap thong tin tu file");
		printf("\n3/ Luu du lieu ra file");
		printf("\n4/ xem thong tin");
		printf("\n5/ thoat chuong trinh");
		scanf_s("%d", &chon);
		switch (chon)
		{
		case 5 :
				exit = true;
				break;
		case 1:
			nhapmang(dssv, n);
			xuatmang(dssv, n);
			break;
		case 4:
			xuatmang(dssv, n);
			break;
		case 2:
			nhapdulieutuFILE(dssv, n);
			break;
		case 3:
			luuFile(dssv, n);
			break;
		}
	}
	while (!exit);
	
	_getch();
}