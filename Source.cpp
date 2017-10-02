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
	printf("nhap n");
	scanf_s("%d", &m);
	for (int i = n; i < m+n; i++)
	{
		printf("nhap ho ten");
		scanf_s("%s", &dsSV[i].hoten);


		n++;
	}

}




void main()
{
	printf("hi");
	printf("nhap ten");
	_getch();
}