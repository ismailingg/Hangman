
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main(){
	FILE *srcfile = fopen("sportsfile.txt", "r");
	if (srcfile==NULL){
		perror("error in openin the provided file");
		return 1;
	}
	srand(time(0));
	int randword= rand()%43 + 1;//19
	int linenum=1;
	char word[100];
	char selectedword[100];
	while(fgets(word,sizeof(word),srcfile)!=NULL){
		if(linenum==randword){
			strcpy(selectedword,word);
			break;
		}
		linenum++;	
	}         
	int i,space;
	
	fclose(srcfile);
//	printf("%s\n",selectedword);
    int len=strlen(selectedword)-1;
    for(i=0;i<len;i++){
    	if(selectedword[i]==' '){
    		len=len-1;
    		space=i+1;
		}
	}
	char guess;
	int k,count=0;
    printf("your word is a type of sport and it has %d letters and a space at %d. \n you can have 5 wrong turns after which you will move 10 boxes back. Guess your word\nspace at 0 means no space\n",len,space);
    int len2=len;
    char wordprint[25];
    int mistakes=0,flag,p;
    for (int i = 0; i < len; i++) {
        if (selectedword[i] == ' ') {
            wordprint[i] = ' ';
        } else {
            wordprint[i] = '-';
        }
    }
    
    wordprint[len] = '\0';
    selectedword[len] = '\0';
    
    
    printf("\n%s\n",wordprint);
    
    while (mistakes < 5) {
        char ans;
        
        int correctGuess = 0;

        printf("Enter your letter: ");
        scanf(" %c", &ans);

        for (int m = 0; m < len; m++) {
            if (ans == selectedword[m]) {
                wordprint[m] = ans;
                correctGuess = 1;
            }
        }

        printf("%s\n", wordprint); 

        if(correctGuess){
		
        if (strcmp(wordprint, selectedword) == 0) {
            printf("Congratulations! You're the winner!\n");
            flag++;
           break;
        }
//        for(i=0;i<len-1;i++){
//        	if(wordprint[i]==selectedword[i]){
//        		flag++;
//			}
//			if(flag==len-1){
//				 printf("Congratulations! You're the winner!\n");
//				 break;
//			}
//		}
    }
    
    
        if (!correctGuess) {
            mistakes++;
            printf("Sorry, wrong try. You have %d lives left.\n", 5 - mistakes);
        }
        if(flag==1){
        	break;
		}
    }
//    if(flag>0){
//    	return 1; //return 1 ke mtlb player has won hangman and he wins.
//	}

    if (mistakes == 5) {
        printf("You're out of lives. Game over!\n");
        return 0;//yahan pe ye hoga ke agar function 0 return kre mtlb player hangman mai haargya and he will be moved a row back i.e i=i-1
    }

    
}












