#include<stdio.h>
int main(){
    int choice;
    int arr[100],soPhanTu;
    int position;
    int giaTri;
    do{
        printf("1. Nhập số phần tử cần nhập và giá trị của các phần tử\n");
        printf("2. In ra giá trị của phần tử đang quản lý\n");
        printf("3. In ra giá trị lớn nhất của mảng\n");
        printf("4. In ra các phần tử là số nguyên tố trong mảng\n");
        printf("5. Thêm một phần tử vào trong mảng\n");
        printf("6. Xóa phần tử trong mảng\n");
        printf("7. Sắp xếp mảng theo thứ tự tăng dần\n");
        printf("8. Tìm kiếm phần tử\n");
        printf("9. Thoát\n");
        printf("\nmoi ban nhap lua chon: ");
        scanf("%d",&choice);
        switch(choice){
		    case 1:

                printf("Nhap so luong phan tu cho mang (1-100): ");
			    scanf("%d", &soPhanTu);
                if (soPhanTu<0 || soPhanTu > 100)
                {
                    printf("Nhap so loi roi");
                    continue;
                }
			    printf("Nhap cac phan tu cho mang:\n ");
			    for(int i=0; i<soPhanTu;i++){
				    printf("Nhap phan tu thu %d cho mang: ", i+1);
				    scanf("%d", &arr[i]);
			    }
                printf("\n");
			    break;
			case 2: 
                printf("%d\n",soPhanTu);
                printf("\nPhan tu trong mang la: ");
                for (int i = 0; i < soPhanTu; i++){
                    printf("%3d",arr[i]);
                }
                printf("\n");
			    break; 
			case 3: 
                int max =arr[0];
                for (int i = 0; i < soPhanTu; i++){
                    if(arr[i]>max){
                        max = arr[i];
                    }
                }
                printf("\nphan tu lon nhat trong mang la: %d ",max);
                printf("\n");
			    break;
			case 4: 
                printf("\n mang có so nguyen to la:");
                for (int i = 0; i < soPhanTu; i++) {
                        int number = arr[i];
                        if (number < 2) {
                            continue;
                        }
                        int flag = 0;
                        for (int j = 2; j * j <= number; j++) {
                            if (number % j == 0) {
                                flag = 1;
                                break;
                            }
                        }

                        if (flag == 0) {
                            printf("%d ", number); 
                        }
                    }
                printf("\n");
			    break;
            case 5:
                 printf("Nhap vi tri muon them vao mang (1-%d): ", soPhanTu + 1);
                scanf("%d", &position);
                if (position < 1 || position > soPhanTu + 1) {
                    printf("Vi tri khong hop le!\n");
                    return 1;
                }
                printf("Nhap gia tri muon them vao: ");
                scanf("%d", &giaTri);
                for (int i = soPhanTu; i >= position; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[position - 1] = giaTri;
                soPhanTu++;
                break;
            case 6:
                fflush(stdin);
                printf("\nnhap vi tri can xoa (từ 1 đến %d): ", soPhanTu );
                scanf("%d", &position);
                if (position < 0 || position > soPhanTu) {
                    printf("Vị trí không hợp lệ.\n");
                } else {
                    for (int i = position-1; i <= soPhanTu ; i++) {
                        arr[i] = arr[i + 1];
                    }
                    soPhanTu--;
                    printf("Da xoa phan tu thanh cong\n");
                }
                printf("\n");
                break;
            case 7:
                fflush(stdin);
                for(int i=0;i<soPhanTu-1;i++){
                    for(int j=0; j<soPhanTu-i-1;j++){
                        if (arr[j] > arr[j + 1]) {
                                int temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                            }
                        }
                }
                printf("\n Mang da duoc sap xep");
                printf("\n");
                break;
            case 8:
                fflush(stdin);
                int search;
                printf("\nNhap phan tu can tim kiem: ");
                scanf("%d",&search);
                int check =-1;
                for(int i = 0; i<soPhanTu;i++){
                    if(search == arr[i]){
                        check = i;
                    }
                }
                if(check != -1){
                    printf("\n vi tri cua phan tu la: %d",check);
                }else{
                    printf("\n phan tu khong ton tai trong mang");
                }
                printf("\n");
                break;
			case 9: // Thoat
                printf("\nBan da thoat");
                break;
			default: 
			    printf("Lua chon khong hop le. Vui long chon lai");
		}
    }while (choice !=9);
    return 0;
}