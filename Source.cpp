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
	for (int i = n; i < m+n; i++)
	{
		printf("nhap ho ten ");
		scanf_s("%s", &dsSV[i].hoten);
		printf("nhap mssv ");
		scanf_s("%s", &dsSV[i].mssv);
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
		printf("sinh vien : %s", dssv[i].hoten);
		printf("MSSV : %s", dssv[i].mssv);
		printf("diem toan : %f", dssv[i].toan);
		printf("diem ly : %f", dssv[i].ly);
		printf("diem hoa : %f", dssv[i].hoa);

	}
}



void main()
{
	int n=0;
	
	SV *dssv=new SV[100];
	nhapmang(dssv, n);
	xuatmang(dssv, n);
	
	_getch();
}