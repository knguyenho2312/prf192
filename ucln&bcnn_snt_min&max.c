#include <stdio.h>

// ----- Cau 1 	
//int main(){
//	int a, b, ucln, bcnn;
//	printf("\nNhap 2 so a va b: ");
//	scanf("%d%d", &a, &b);
//	
//	int x = a, y = b;
//	while(b != 0){
//		int temp = b;
//		b = a % b;
//		a = temp;
//	}
//	ucln = a;
//	bcnn = (x*y)/ucln;
//		
//	printf("UCLN cua %d va %d la: %d\n", x, y, ucln);
//	printf("BCNN cua %d va %d la: %d\n", x, y, bcnn);
//	return 0;
//}



// ----- Cau 2 
int KiemTra(int num){
	if(num < 2){
		return 0;
	}
	for(int i = 2; i < num; i++){
		if(num % i == 0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int n, min_snt = -1, max_snt = -1; //giá trị cao nhất và thấp nhất trong số nguyên tố phải bắt đầu bằng -1 để kiểm tra trong vòng lập đã có số nguyên tố chưa và tránh nhầm lẫn với 0
	
	printf("Nhap n: ");
	scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		if(KiemTra(i)){
			if(min_snt == -1){
				min_snt = i;
			}
			max_snt = i;
		}
	}
	if(min_snt == -1){
		printf("Khong co so nguyen to nao trong khoang tu 1 den %d", n);
	}
	else{
		printf("So nguyen to lon nhat va nho nhat la: %d va %d\n", min_snt, max_snt);
	}
}


