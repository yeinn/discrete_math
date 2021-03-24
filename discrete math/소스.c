#include <stdio.h>
#include <math.h> //수학 계산을 위한 헤더파일

void isPrime(int n) { //입력한 수가 소수인지 확인하는 함수, 입력할 변수인 n을 선언
	int k, d; // 변수 k와 d를 선언함
	if (n == 2) { //n이 2일 때, True를 반환함
		printf("True");
	}
	else if (n % 2 == 0) { //n을 2로 나눈 나머지가 0일 때, 즉 n이 2의 배수이면 False를 반환함
		printf("False");
	}
	else { // n이 홀수일 경우
		k = (int)sqrt(n); //k는 루트n 임을 선언
		d = 3;
		while (d <= k) { // d가 k보다 같거나 작을 때까지 반복함
			if (n % d == 0) { //만약 n을 d로 나눈 나머지가 0이면 False를 반환함
				printf("False");
				return;
			}
			d += 2; // d = d+2 d에 2를 더함
		}
		printf("True"); //3~k까지 1과 자기자신을 제외한 약수가 없을 경우, true를 반환함 
	
	} 
	return; //함수 종료
}

int Euclid(int a, int b) { // 유클리드 계산을 진행하는 함수, 입력할 변수 a, b 선언
	if (a == 0 && b == 0) // 만약 a와 b가 0이면 0을 반환함
		return 0;
	if (b == 0) // 만약 b가 0이면 a를 반환함
		return a;
	else
		return Euclid(b, a % b); // 이 외의 경우, 즉 b가 0이 아닐때에는 b와 a를 b로 나눈 나머지를 다시 if 절로 돌아가 반환값이 나올 때까지 계속해서 비교함
	
}


int main() { // 위에서 선언한 함수들을 불러와 프로그램을 수행할 메인함수
	int n,a,b; // 계산에 입력할 n,a,b 변수 선언
	scanf("%d %d %d", &n, &a, &b); // n,a,b 변수를 입력받기 위한 함수
	isPrime(n); //isPrime 함수 불러와 입력받은 n이 소수인지 판별함 =>결과가 true 혹은 false로 반환됨
	printf(" %d", Euclid(a, b)); // Euclid 함수 결과를 출력함
	return 0; //종료
}