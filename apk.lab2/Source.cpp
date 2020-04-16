#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main() {
	clock_t start = clock(), end;
	int arr_1[8]{ 1,2,3,4,5,6,7,8 }, arr_2[8]{ 9,16,5,10,15,2,21,22 }, arr_avg[8], glob = 10000000, arr_size = 8;;
	int global_counter = 0, counter = 0, k;
	while (1) {
		system("cls");
		printf("Welcome to array avger!\n");
		cout << "1 - Redact parameters" << endl << "2 - Show result" << endl << "3 - Exit program" << endl;
		cin >> k;
		if (k == 3) break;
		switch (k) {
		case 1: {  }
			  break;
		case 2: {
			while (counter < 8) {
				cout << arr_1[counter] << " ";
				counter++;
			}
			cout << endl;
			counter = 0;
			while (counter < 8) {
				cout << arr_2[counter] << " ";
				counter++;
			}
			counter = 0;
			cout << endl;
			start = clock();
			while (global_counter < glob) {
				while (counter < arr_size) {
					arr_avg[counter] = (arr_1[counter] + arr_2[counter]) / 2;
					counter++;
				}
				counter = 0;
				global_counter++;
			}
			printf("C result: ");
			end = clock();
			while (counter < 8) {
				cout << arr_avg[counter] << " ";
				counter++;
			}
			counter = 0;
			printf("\nTime: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
			while (counter < arr_size) {
				arr_avg[counter] = 0;
				counter++;
			}
			counter = 0;
			start = clock();
			_asm {
				mov edi, glob
				loop_start_1 :

				pusha
					xor esi, esi
					xor eax, eax
					mov ecx, arr_size
					mov ebx, 2

					loop_start_2 :
				mov eax, 0
					add eax, arr_1[esi]
					add eax, arr_2[esi]
					idiv ebx
					mov arr_avg[esi], eax
					add esi, 4
					dec ecx
					jnz loop_start_2

					popa
					dec edi
					jnz loop_start_1
			}
			end = clock();
			printf("Assembler result: ");
			while (counter < arr_size) {
				cout << arr_avg[counter] << " ";
				counter++;
			}
			counter = 0;
			printf("\nTime: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

			while (counter < arr_size) {
				arr_avg[counter] = 0;
				counter++;
			}
			counter = 0;

			start = clock();


			_asm {
				mov edi, glob
				mmx_loop_start_1 :
				xor esi, esi
					mov ecx, arr_size

					mmx_loop_start_2 :
				movd mm0, arr_1[esi]
					movd mm1, arr_2[esi]
					pavgw mm0, mm1
					movd arr_avg[esi], mm0
					add esi, 4
					dec ecx
					jnz mmx_loop_start_2
					emms

					dec edi
					jnz mmx_loop_start_1
			}
			end = clock();
			printf("MMX result: ");
			while (counter < arr_size) {
				cout << arr_avg[counter] << " ";
				counter++;
			}
			printf("\nTime: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
			system("pause");
		} break;
		}
	}
}