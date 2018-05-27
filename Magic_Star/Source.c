#include<stdio.h>


char input[7][11];
int fix[13];
int use[13];
int ans[13];
int result[13];
int flag;

int sum1(int num){
	return num + ans[1] + ans[3] + ans[6] + ans[8];
}

int sum2(int num){
	return num + ans[1] + ans[4] + ans[7] + ans[11];
}

int sum3(int num){
	return num + ans[2] + ans[3] + ans[4] + ans[5];
}

int sum4(int num){
	return num + ans[8] + ans[9] + ans[10] + ans[11];
}

int sum5(int num){
	return num + ans[2] + ans[6] + ans[9] + ans[12];
}

int sum6(int num){
	return num + ans[5] + ans[7] + ans[10] + ans[12];
}


int check(int num, int cnt){
	if (cnt == 1){
		if (sum1(num) <= 26 && sum2(num) <= 26)
			return 1;
		else
			return 0;
	}
	else if (cnt == 2){
		if (sum3(num) <= 26 && sum5(num) <= 26)
			return 1;
		else
			return 0;
	}
	else if (cnt == 3){
		if (sum1(num) <= 26 && sum3(num) <= 26)
			return 1;
		else
			return 0;
	}
	else if (cnt == 4){
		if (sum2(num) <= 26 && sum3(num) <= 26)
			return 1;
		else
			return 0;
	}
	else if (cnt == 5){
		if (sum3(num) <= 26 && sum6(num) <= 26)
			return 1;
		else
			return 0;
	}
	else if (cnt == 6){
		if (sum1(num) <= 26 && sum5(num) <= 26)
			return 1;
		else
			return 0;
	}
	else if (cnt == 7){
		if (sum2(num) <= 26 && sum6(num) <= 26)
			return 1;
		else
			return 0;
	}
	else if (cnt == 8){
		if (sum1(num) <= 26 && sum4(num) <= 26)
			return 1;
		else
			return 0;
	}
	else if (cnt == 9){
		if (sum4(num) <= 26 && sum5(num) <= 26)
			return 1;
		else
			return 0;
	}
	else if (cnt == 10){
		if (sum4(num) <= 26 && sum6(num) <= 26)
			return 1;
		else
			return 0;
	}
	else if (cnt == 11){
		if (sum2(num) <= 26 && sum4(num) <= 26)
			return 1;
		else
			return 0;
	}
	else if (cnt == 12){
		if (sum5(num) <= 26 && sum6(num) <= 26)
			return 1;
		else
			return 0;
	}
	else{
		printf("impossible\n");
	}
}

void DFS(int cnt){
	int i;

	/*if (cnt == 7 && ans[1] == 6 && ans[2] == 1 && ans[3] == 9 && ans[4] == 4 && ans[5] == 12 && ans[6] == 8){
		printf("aaaa\n");
		printf("bbbb\n");
	}*/

	/*for (i = 1; i <= 12; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");*/

	if (flag == 1) return;
	
	if (cnt == 13){
		for (i = 1; i <= 12; i++){
			//printf("%d ", ans[i]);
			result[i] = ans[i];
		}
		//printf("\n");
		flag = 1;
		return;
	}

	else if (ans[cnt] != 0)   //fix
		DFS(cnt + 1);
			

	else {

		for (i = 1; i <= 12; i++){

			if (use[i] != 0)
				continue;

				/*else if (fix[i] != 0){
					ans[cnt] = i;
					DFS(cnt + 1);
					}*/
			else if (check(i,cnt)){
				ans[cnt] = i;
				use[i] = cnt;
				DFS(cnt + 1);
				ans[cnt] = 0;
				use[i] = 0;
			}
		}
	}
}


int main(){
	int i, j;
	char dummy;
	for (i = 1; i <= 5; i++){
		//scanf("%s", input[i]+1);
		gets(input[i] + 1);
		for (j = 1; j <= 9; j++){
			if (input[i][j] != 'x'&&input[i][j] != '.'){
				//if (input[i][j] == 'A')
				if (i==1&&j==5) fix[(int)(input[i][j] - 'A' + 1)] = 1;
				else if (i == 2 && j == 2) fix[(int)(input[i][j] - 'A' + 1)] = 2;
				else if (i == 2 && j == 4) fix[(int)(input[i][j] - 'A' + 1)] = 3;
				else if (i == 2 && j == 6) fix[(int)(input[i][j] - 'A' + 1)] = 4;
				else if (i == 2 && j == 8) fix[(int)(input[i][j] - 'A' + 1)] = 5;
				else if (i == 3 && j == 3) fix[(int)(input[i][j] - 'A' + 1)] = 6;
				else if (i == 3 && j == 7) fix[(int)(input[i][j] - 'A' + 1)] = 7;
				else if (i == 4 && j == 2) fix[(int)(input[i][j] - 'A' + 1)] = 8;
				else if (i == 4 && j == 4) fix[(int)(input[i][j] - 'A' + 1)] = 9;
				else if (i == 4 && j == 6) fix[(int)(input[i][j] - 'A' + 1)] = 10;
				else if (i == 4 && j == 8) fix[(int)(input[i][j] - 'A' + 1)] = 11;
				else if (i == 5 && j == 5) fix[(int)(input[i][j] - 'A' + 1)] = 12;
			
			}
		
		}
		//scanf("%c", &dummy);
	}

	//for (i = 1; i <= 5; i++){
	//	for (j = 1; j <= 9; j++){
	//		scanf("%s", &input[i][j]);
	//		if (input[i][j] != 'x'&&input[i][j] != '.'){
	//			//if (input[i][j] == 'A')
	//			if (i==1&&j==5) fix[(int)(input[i][j] - 'A' + 1)] = 1;
	//			else if (i == 2 && j == 2) fix[(int)(input[i][j] - 'A' + 1)] = 2;
	//			else if (i == 2 && j == 4) fix[(int)(input[i][j] - 'A' + 1)] = 3;
	//			else if (i == 2 && j == 6) fix[(int)(input[i][j] - 'A' + 1)] = 4;
	//			else if (i == 2 && j == 8) fix[(int)(input[i][j] - 'A' + 1)] = 5;
	//			else if (i == 3 && j == 3) fix[(int)(input[i][j] - 'A' + 1)] = 6;
	//			else if (i == 3 && j == 7) fix[(int)(input[i][j] - 'A' + 1)] = 7;
	//			else if (i == 4 && j == 2) fix[(int)(input[i][j] - 'A' + 1)] = 8;
	//			else if (i == 4 && j == 4) fix[(int)(input[i][j] - 'A' + 1)] = 9;
	//			else if (i == 4 && j == 6) fix[(int)(input[i][j] - 'A' + 1)] = 10;
	//			else if (i == 4 && j == 8) fix[(int)(input[i][j] - 'A' + 1)] = 11;
	//			else if (i == 5 && j == 5) fix[(int)(input[i][j] - 'A' + 1)] = 12;
	//		
	//		}
	//	
	//	}
	//	scanf("%c", &dummy);
	//}

	//for (i = 1; i <= 5; i++){
	//	for (j = 1; j <= 9; j++){
	//		printf("%c", input[i][j]);
	//	}
	//	printf("\n");
	//}


	//fix[input[1][5] - '0'] = 1;

	

	for (i = 1; i <= 12; i++){
		use[i] = fix[i];
		if (use[i] != 0)
			ans[use[i]] = i;
		//printf("%d ", fix[i]);
	}

	DFS(1);

	for (i = 1; i <= 5; i++){
		for (j = 1; j <= 9; j++){
			if (input[i][j] != '.'){
				if (i == 1 && j == 5) input[i][j] = result[1] + 'A' - 1;
				else if (i == 2 && j == 2) input[i][j] = result[2] + 'A' - 1;
				else if (i == 2 && j == 4) input[i][j] = result[3] + 'A' - 1;
				else if (i == 2 && j == 6) input[i][j] = result[4] + 'A' - 1;
				else if (i == 2 && j == 8) input[i][j] = result[5] + 'A' - 1;
				else if (i == 3 && j == 3) input[i][j] = result[6] + 'A' - 1;
				else if (i == 3 && j == 7) input[i][j] = result[7] + 'A' - 1;
				else if (i == 4 && j == 2) input[i][j] = result[8] + 'A' - 1;
				else if (i == 4 && j == 4) input[i][j] = result[9] + 'A' - 1;
				else if (i == 4 && j == 6) input[i][j] = result[10] + 'A' - 1;
				else if (i == 4 && j == 8) input[i][j] = result[11] + 'A' - 1;
				else if (i == 5 && j == 5) input[i][j] = result[12] + 'A' - 1;
			}
		}
		input[i][11] = '\0';
		printf("%s\n", input[i]+1);
	}

	//printf("aaaaa\n");

	//for (i = 1; i <= 5; i++){
	//	for (j = 1; j <= 9; j++){
	//		if (input[i][j] != '.'){
	//			if (i == 1 && j == 5) input[i][j] = result[1] + 'A' - 1;
	//			else if (i == 2 && j == 2) input[i][j] = result[2] + 'A' - 1;
	//			else if (i == 2 && j == 4) input[i][j] = result[3] + 'A' - 1;
	//			else if (i == 2 && j == 6) input[i][j] = result[4] + 'A' - 1;
	//			else if (i == 2 && j == 8) input[i][j] = result[5] + 'A' - 1;
	//			else if (i == 3 && j == 3) input[i][j] = result[6] + 'A' - 1;
	//			else if (i == 3 && j == 7) input[i][j] = result[7] + 'A' - 1;
	//			else if (i == 4 && j == 2) input[i][j] = result[8] + 'A' - 1;
	//			else if (i == 4 && j == 4) input[i][j] = result[9] + 'A' - 1;
	//			else if (i == 4 && j == 6) input[i][j] = result[10] + 'A' - 1;
	//			else if (i == 4 && j == 8) input[i][j] = result[11] + 'A' - 1;
	//			else if (i == 5 && j == 5) input[i][j] = result[12] + 'A' - 1;
	//		}
	//		printf("%c", input[i][j]);
	//	}
	//	printf("\n");
	//}

	//for (i = 1; i <= 12; i++){
	//	printf("%d ", result[i]);
	//}
	//printf("\n");

}
