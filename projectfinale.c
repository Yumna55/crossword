// A three level crossword puzzle
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include <pthread.h>
#include <Windows.h>

//Function prototypes
void Calleasy();
void Callmedium();
void Callhard();
void Viewscore(int);
void edit_score(int, char []);
void show_record();
void* countdown_timer(void*);

//Global variables
char clue;
int score=0;
char playername[20];
int cancel_timer =0;


void *countdown_timer(void *time_pointer) {
	/*Here using a thread to count down from a specified time limit (passed in as an argument as a pointer to an integer) 
	and display the remaining time in minutes and seconds.*/
	int time_limit = *((int*)time_pointer);
	int remaining_time = (int) time_limit;
	while (remaining_time > 0 && !cancel_timer) {
	/*loop will continue to execute as long as the cancel_timer variable is false
	and as long as the remaining time is greater than zero*/

		printf("\033[5;60H");
		printf("Time remaining: %02d:%02d\n", remaining_time / 60, remaining_time % 60);
		remaining_time--;
		sleep(1);

	}
	if(cancel_timer) {
		/*checking if the timer has been canceled, and if so, it exits the thread*/
		pthread_exit(NULL);
	}
	system("CLS");
	printf("\n\n\n\t\t\t\t______Time's Up!_____\n");
	Viewscore(score);
	pthread_exit(NULL);
}

	//Print easy level
void print(char st[],char st1[],char st2[],char st3[],char st4[],char st5[],char st6[],char st7[],char st8[]) { 
	system("color 6f");
	int puz[4][4],num=1;
	char letter;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			if(i==1 && j==1) {
				printf("\t %c ",st[0]);
			} else if(i==2 && j==2) {
				printf("\t %c ",st1[2]);
			} else if(i==3 && j==3) {
				printf("\t %c ",st2[4]);
			} else if(i==0 && j==1 || i==0 && j==2 || i==0 && j==3) {
				printf("\t %d ",num++);
			} else if(i==0 && j==0) {
				printf("\t %c ",letter='*');
			} else if(i==1 && j==0 || i==2 && j==0 || i==3 && j==0) {
				printf("\t %d ",num++);
			} else if (i==3 && j==1) {
				printf("\t %s ",st3);
			} else if (i==1 && j==2) {
				printf("\t %s ",st4);
			} else if (i==1 && j==3) {
				printf("\t %s ",st5);
			} else if (i==2 && j==1) {
				printf("\t %s ",st6);
			} else if (i==2 && j==3) {
				printf("\t %s ",st7);
			} else {
				printf("\t %s ",st8);
			}
		}
		printf("\n\n");
	}
}
void puzzle(char st[],char st1[],char st2[],char st3[],char st4[],char st5[],char st6[],char st7[],char st8[],int time_limit) {
//Easy level puzzle
	system("color 6f");
	char choice;
	print(st,st1,st2,st3,st4,st5,st6,st7,st8);
	pthread_t timer_thread;
	pthread_create(&timer_thread,NULL,countdown_timer,&time_limit);


	int num=1;
	char letter,answer[1];
	int reference;
	while (1) {

		printf("\n\n\n\n\n\t Enter the refernce of the box you want to fill: \n (First column then row e.g. 15 )");
		scanf("%d",&reference);
		while(reference<1 || reference>35) {
			printf("Invalid reference number. Please enter a valid number.\n");

			cancel_timer =1;
			pthread_join(timer_thread, NULL);
			main();
			break;
		}
		system("CLS");
		switch(reference) {
			case 24:
				print(st,st1,st2,st3,st4,st5,st6,st7,st8);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st[1] || answer[0]==st[2]) {

					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st4,answer);
					system("CLS");
					print(st,st1,st2,st3,st4,st5,st6,st7,st8);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print(st,st1,st2,st3,st4,st5,st6,st7,st8);
				}
				break;
			case 34:
				print(st,st1,st2,st3,st4,st5,st6,st7,st8);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st[3] || answer[0]==st[4]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st5,answer);
					system("CLS");
					print(st,st1,st2,st3,st4,st5,st6,st7,st8);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print(st,st1,st2,st3,st4,st5,st6,st7,st8);
				}
				break;
			case 15:
				print(st,st1,st2,st3,st4,st5,st6,st7,st8);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				fflush(stdin);
				if(answer[0]==st1[0] || answer[0]==st1[1]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st6,answer);
					system("CLS");
					print(st,st1,st2,st3,st4,st5,st6,st7,st8);


				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print(st,st1,st2,st3,st4,st5,st6,st7,st8);
				}
				break;


			case 35:
				print(st,st1,st2,st3,st4,st5,st6,st7,st8);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st1[3] || answer[0]==st1[4]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st7,answer);
					system("CLS");
					print(st,st1,st2,st3,st4,st5,st6,st7,st8);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print(st,st1,st2,st3,st4,st5,st6,st7,st8);
				}
				break;
			case 16:
				print(st,st1,st2,st3,st4,st5,st6,st7,st8);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st2[0] || answer[0]==st2[1]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st3,answer);
					system("CLS");
					print(st,st1,st2,st3,st4,st5,st6,st7,st8);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print(st,st1,st2,st3,st4,st5,st6,st7,st8);
				}
				break;
			case 26:
				print(st,st1,st2,st3,st4,st5,st6,st7,st8);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st2[2] || answer[0]==st2[3]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st8,answer);
					system("CLS");
					print(st,st1,st2,st3,st4,st5,st6,st7,st8);


				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print(st,st1,st2,st3,st4,st5,st6,st7,st8);
				}
				break;
			case 0:
				cancel_timer =1;
				pthread_join(timer_thread, NULL);
				main();
				break;

		}
		if(score==30) {
			printf("\n\n\n\t\t Press E to proceed further:");
			if (toupper(getch())=='E' );
			{
				cancel_timer =1;
				pthread_join(timer_thread, NULL);
				Viewscore(score);
				break;
			}//end nested if

		}// end if



	}//End loop
}

//Medium level print

void print_medium(char st[],char st1[],char st2[],char st3[],char st4[],char st5[],char st6[],char st7[],char st8[],char st9[],char st10[],char st11[]) {
	system("color 2f");
	int num=1;
	char letter;
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			if(i==0 && j==0) {
				printf("\t %c ",letter='*');
			} else if(i==0 && j==1 || i==0 && j==2 || i==0 && j==3 || i==0 && j==4) {
				printf("\t %d ",num++);
			} else if(i==1 && j==0 || i==2 && j==0 || i==3 && j==0 || i==4 && j==0) {
				printf("\t %d ",num++);
			} else if(i==1 && j==1) {
				printf("\t %c ",st[0]);
			} else if(i==1 && j==1) {
				printf("\t %c ",st[0]);
			} else if(i==1 && j==2) {
				printf("\t %s ",st4);
			} else if(i==1 && j==3) {
				printf("\t %s ",st5);
			} else if(i==1 && j==4) {
				printf("\t %s ",st6);
			} else if(i==2 && j==1) {
				printf("\t %s ",st7);
			} else if(i==2 && j==2) {
				printf("\t %c ",letter=' ');
			} else if(i==2 && j==3) {
				printf("\t %c ",letter=' ');
			} else if(i==2 && j==4) {
				printf("\t %c ",st1[4]);
			} else if(i==3 && j==1) {
				printf("\t %c ",st2[0]);
			} else if(i==3 && j==2) {
				printf("\t %c ",letter=' ');
			} else if(i==3 && j==3) {
				printf("\t %c ",letter=' ');
			} else if(i==3 && j==4) {
				printf("\t %s ",st8);
			} else if(i==4 && j==1) {
				printf("\t %s ",st9);
			} else if(i==4 && j==2) {
				printf("\t %s ",st10);
			} else if(i==4 && j==3) {
				printf("\t %s ",st11);
			} else if(i==4 && j==4) {
				printf("\t %c ",st3[6]);
			}
		}
		printf("\n\n");
	}
}

//Medium level puzzle
void medium(char st[],char st1[],char st2[],char st3[],char st4[],char st5[],char st6[],char st7[],char st8[],char st9[],char st10[],char st11[],int time_limit) {

	system("color 2f");
	pthread_t timer_thread;
	pthread_create(&timer_thread,NULL,countdown_timer,&time_limit);
	print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
	int reference;
	char answer[1],choice;

	while(1) {
		printf("\n\n\n\n\n\t Enter the refernce of the box you want to fill: \n (First column then row e.g. 35 )");
		scanf("%d",&reference);
		while(reference<1 || reference>47) {
			printf("Invalid reference number. Please enter a valid number.\n");

			cancel_timer =1;
			pthread_join(timer_thread, NULL);
			main();
			break;
		}
		system("CLS");
		switch(reference) {
			case 25:
				print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st[1] || answer[0]==st[2]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st4,answer);
					system("CLS");
					print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				}
				break;
			case 35:
				print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st[3] || answer[0]==st[4]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st5,answer);
					system("CLS");
					print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				}
				break;
			case 45:
				print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st[5] || answer[0]==st[6]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st6,answer);
					system("CLS");
					print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				}
				break;
			case 16:
				print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st1[0] || answer[0]==st1[1]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st7,answer);
					system("CLS");
					print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				}
				break;
			case 47:
				print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				printf("\n\n\t\t > Fill the box: \n");;
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st2[3] || answer[0]==st2[4]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st8,answer);
					system("CLS");
					print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				}
				break;
			case 18:
				print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st3[0] || answer[0]==st3[1]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st9,answer);
					system("CLS");
					print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				}
				break;
			case 28:
				print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st3[2] || answer[0]==st3[3]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st10,answer);
					system("CLS");
					print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				}
				break;
			case 38:
				print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st3[4] || answer[0]==st3[5]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st11,answer);
					system("CLS");
					print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11);
				}
				break;
			case 0:
				cancel_timer =1;
				pthread_join(timer_thread, NULL);
				main();
				break;
		}//end switch
		if(score==70) {
			printf("Press E to proceed further:");
			if (toupper(getch())=='E' );
			{
				cancel_timer =1;
				pthread_join(timer_thread, NULL);
				Viewscore(score);
				break;

			}
		}

	}//end loop

}//end function

//HARD level print
void print_hard(char st[],char st1[],char st2[],char st3[],char st4[],char st5[],char st6[],char st7[],char st8[],char st9[],char st10[],char st11[],char st12[],char st13[],char st14[],char st15[],char st16[],char st17[],char st18[],char st19[]) {
	system("color 4f");
	int num=1;
	char letter;
	for(int i=0; i<6; i++) {
		for(int j=0; j<6; j++) {
			if(i==0 && j==0) {
				printf("\t %c ",letter='*');
			} else if(i==0 && j==1 || i==0 && j==2 || i==0 && j==3 || i==0 && j==4 || i==0 && j==5) {
				printf("\t %d ",num++);
			} else if(i==1 && j==0 || i==2 && j==0 || i==3 && j==0 || i==4 && j==0 || i==5 && j==0) {
				printf("\t %d ",num++);
			} else if(i==1 && j==1) {
				printf("\t %c ",st[0]);
			} else if(i==1 && j==2) {
				printf("\t %s ",st5);
			} else if(i==1 && j==3) {
				printf("\t %s ",st6);
			} else if(i==1 && j==4) {
				printf("\t %s ",st7);
			} else if(i==1 && j==5) {
				printf("\t %c ",st[7]);
			} else if(i==2 && j==1) {
				printf("\t %s ",st8);
			} else if(i==2 && j==2) {
				printf("\t %c ",letter=' ');
			} else if(i==2 && j==3) {
				printf("\t %c ",st1[3]);
			} else if(i==2 && j==4) {
				printf("\t %c ",letter=' ');
			} else if(i==2 && j==5) {
				printf("\t %s ",st9);
			} else if(i==3 && j==1) {
				printf("\t %s ",st10);
			} else if(i==3 && j==2) {
				printf("\t %c ",st2[2]);
			} else if(i==3 && j==3) {
				printf("\t %s ",st11);
			} else if(i==3 && j==4) {
				printf("\t %s ",st12);
			} else if(i==3 && j==5) {
				printf("\t %s ",st13);
			} else if(i==4 && j==1) {
				printf("\t %s ",st14);
			} else if(i==4 && j==2) {
				printf("\t %c ",letter=' ');
			} else if(i==4 && j==3) {
				printf("\t %s ",st15);
			} else if(i==4 && j==4) {
				printf("\t %c ",letter=' ');
			} else if(i==4 && j==5) {
				printf("\t %c ",st3[6]);
			} else if(i==5 && j==1) {
				printf("\t %s ",st16);
			} else if(i==5 && j==2) {
				printf("\t %s ",st17);
			} else if(i==5 && j==3) {
				printf("\t %c ",st4[4]);
			} else if(i==5 && j==4) {
				printf("\t %s ",st18);
			} else if(i==5 && j==5) {
				printf("\t %s ",st19);
			}
		}
		printf("\n\n");
	}
}
//Hard level puzzle
void hard(char st[],char st1[],char st2[],char st3[],char st4[],char st5[],char st6[],char st7[],char st8[],char st9[],char st10[],char st11[],char st12[],char st13[],char st14[],char st15[],char st16[],char st17[],char st18[],char st19[],int time_limit) {
	system("color 4f");
	pthread_t timer_thread;
	pthread_create(&timer_thread,NULL,countdown_timer,&time_limit);
	print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
	int reference;
	char answer[1],choice;
	while(1) {
		printf("\n\n\n\n\n\t Enter the refernce of the box you want to fill: \n\n\n\n\n\t\t (First column then row e.g. 26 )");
		scanf("%d",&reference);
		while(reference<1 || reference>510) {
			printf("Invalid reference number. Please enter a valid number.\n");

			cancel_timer =1;
			pthread_join(timer_thread, NULL);
			main();
			break;
		}
		system("CLS");
		switch(reference) {
			case 26:
				print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st[1] || answer[0]==st[2]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st5,answer);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				}
				break;
			case 36:
				print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st[3] || answer[0]==st[4]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st6,answer);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				}
				break;
			case 46:
				print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st[5] || answer[0]==st[6]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st7,answer);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				}
				break;
			case 17:
				print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st1[0] || answer[0]==st1[1]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st8,answer);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				}
				break;
			case 57:
				print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st1[5] || answer[0]==st1[6]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st9,answer);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				}
				break;
			case 18:
				print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st2[0] || answer[0]==st2[1]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st10,answer);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				}
				break;
			case 38:
				print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st2[3] || answer[0]==st2[4]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st11,answer);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				}
				break;
			case 48:
				print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st2[5] || answer[0]==st2[6]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st12,answer);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				}
				break;
			case 58 :
				print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st2[7] || answer[0]==st2[8]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st13,answer);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				}
				break;
			case 19:
				print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st3[0] || answer[0]==st3[1]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st14,answer);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				}
				break;
			case 39:
				print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st3[3] || answer[0]==st3[4]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st15,answer);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				}
				break;
			case 110:
				print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st4[0] || answer[0]==st4[1]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st16,answer);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				}
				break;
			case 210:
				print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st4[2] || answer[0]==st4[3]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st17,answer);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				}
				break;
			case 410:
				print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st4[5] || answer[0]==st[6]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st18,answer);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				}
				break;
			case 510:
				print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				printf("\n\n\t\t > Fill the box: \n");
				fflush(stdin);
				scanf("%s",&answer[0]);
				if(answer[0]==st4[7] || answer[0]==st4[8]) {
					printf("Correct!!! \n Score+5 \n");
					sleep(1);
					score=score+5;
					strcpy(st19,answer);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				} else {
					printf("Wrong Answer \n");
					sleep(1);
					system("CLS");
					print_hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19);
				}
				break;
			case 0:
				cancel_timer =1;
				pthread_join(timer_thread, NULL);
				main();
				break;
		}
		if(score==145) {
			printf("Press E to proceed further:");
			if (toupper(getch())=='E' );
			{
				cancel_timer =1;
				pthread_join(timer_thread, NULL);
				Viewscore(score);
				break;

			}
		}//
	}//end loop
}

int main() {
	system("color 0b");

	char choice;
	char choose;
		// MAIN screen
mainhome:
	system("cls");
	printf("\n\t\t\tC PROGRAM CROSS CODE PUZZLE\n");
	printf("\n\t\t________________________________________");

	printf("\n\n\t\t\t   Welcome To The Game");
	printf("\n\t\t________________________________________");
	printf("\n\t\t________________________________________");
	printf("\n\n\t\t > Press S Start the Game ");
	printf("\n\t\t > Press V to View the Highest Score  ");
	printf("\n\t\t > Press Any Key to Quit");
	printf("\n\n\t\t > Enter Your Choice : ");

	choice=toupper(getch());
	if(choice=='S' ) {

		system("cls");

		printf("\n\n\n\n\n\n\n\n\n\n\t\t\tRegister Your Name: ");
		gets(playername);


		system("cls");
		printf("\n ------------------  Welcome %s to C Program CROSS WORD PUZZLE GAME --------------------------",playername);
		printf("\n\n Here Are Few Tips For You.");
		printf("\n -------------------------------------------------------------------------");
		printf("\n >> There are 3 levels in this Quiz Game: EASY, MEDIUM AND HARD");
		printf("\n >> You will be given the choice to Choose from any of the Levels");
		printf("\n >> Each Level has Timer Counter. Make sure you Complete the Level in the given time.");
		printf("\n >> In Easy Level you will be given a 3x3 CrossWord Puzzle");
		printf("\n    with a timer of 2 minutes.");
		printf("\n >> In Medium Level you will be given a 4x4 CrossWord Puzzle");
		printf("\n    with a timer of 5 minutes.");
		printf("\n >> In Hard Level you will be given a 5x5 CrossWord Puzzle");
		printf("\n    with a timer of 7 minutes.");
		printf("\n >> When you Begin the Game the Timer will start.");
		printf("\n    To Enter a Letter in the CrossWord you will have to ");
		printf("\n    enter the REFERENCE NUMBER of that specific Alphabet");
		printf("\n >> FOR EXAMPLE: Press 15 for the If you are referring to ");
		printf("\n    1st Column & 5th Row.");
		printf("\n >> There is NO negative marking for WRONG Answers!");
		printf("\n\n\t!!!!!!!!!!!!! ALL THE BEST !!!!!!!!!!!!!");
		printf("\n\n\n\t\t\t Press Y  to start the game!\n");
		printf("\n\t\t\t Press any other key to return to the main menu!");
		if (toupper(getch())=='Y')  {
			system("CLS");
			printf("\n\n\n\t\t > Press E to PLAY EASY Level  ");
			printf("\n\n\n\t\t > Press M to PLAY MEDIUM Level  ");
			printf("\n\n\n\t\t > Press H to PLAY HARD Level  ");
			printf("\n\n\n\t\t > Press P to PLAY Sequentially \n\t\t   EASY >> MEDIUM >> HARD");
			choose=toupper(getch());
			if (choose=='E' ) {
				Calleasy();
			} else if(choose=='M' ) {
				score=30;
				Callmedium();
			} else if (choose=='H' ) {
				score=70;
				Callhard();
			} else if (choose=='P' ) {
				Calleasy();

			} else {
				goto mainhome;
				system("cls");
			}
		} else {
			goto mainhome;
			system("cls");
		}
	} else if(choice=='V' ) {

		show_record();
		goto mainhome;

	}


	return 0;
}
void Calleasy() {

	system("cls");


	int time_limit = 120;
	int* time_pointer = &time_limit;
	pthread_t timer_thread;
	int rc = pthread_create(&timer_thread, NULL, countdown_timer, &time_limit);

	if (rc) {
		printf("Error: unable to create thread, %d\n", rc);
		exit(-1);
	}
	int c=rand()%3;
	if(c==0) {
		char st[5]="LAaBb",st1[5]="OoREe",st2[5]="GgEeT",st3[]="#",st4[]="#",st5[]="#",st6[]="#",st7[]="#",st8[]="#";
		puzzle(st,st1,st2,st3,st4,st5,st6,st7,st8,time_limit);
	}
	if(c==1) {
		char st[5]="ROoDd",st1[5]="AaREe",st2[5]="MmEeN",st3[]="#",st4[]="#",st5[]="#",st6[]="#",st7[]="#",st8[]="#";
		puzzle(st,st1,st2,st3,st4,st5,st6,st7,st8,time_limit);
	}
	if(c==2) {
		char st[5]="BOoWw",st1[5]="UuNOo",st2[5]="TtOoW",st3[]="#",st4[]="#",st5[]="#",st6[]="#",st7[]="#",st8[]="#";
		puzzle(st,st1,st2,st3,st4,st5,st6,st7,st8,time_limit);
	}
	pthread_join(timer_thread, NULL);
	printf("Your Score: %d", score);

}
void Callmedium() {

	system("cls");
	int a=rand()%3;
	if(a==2) {
		MessageBox(0,">>[B---] What does the wind do?\n\n>>[B-L-] A spherical toy\n\n>>[---k] Savekeeper\n\n>>[-e-k] Seven days and nights","Clues",1);
	}
	if(a==1) {
		MessageBox(0,">> I am the beginning of a project, the first step in a process. I am the origin of something new. I am the transformation of raw materials into something useful. I am the opposite of destroy. What am I?\n\n>> I am a woman who works in a household, tending to the needs of the family. I am responsible for cleaning, cooking, and sometimes childcare. I am often present in the background, but my work is essential. I can be live-in or come in regularly. I am a helper and a servant. What am I?\n\n>> I am a currency, used by many European countries. I am the replacement of many national currencies. I am represented by the symbol ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¬. I am used for trade, business and daily transactions. I am recognized all over the world. What am I?\n\n>> I roamed the earth long ago, but now I'm extinct. I am a giant creature, with sharp teeth and a long tail. Some of me had wings, some of me had armor. I come in many shapes and sizes. I am a favorite of children and paleontologists alike. What am I?","CLUES",1);
	}
	if(a==0) {
		MessageBox(0,">> I am a source of joy and laughter, a pastime for the young and old. I can be a game, a sport, or a performance. I bring people together, and I can make memories that last forever. I am something to do, when there's nothing to do. What am I?\n\n>> I am something that is required to complete a transaction, but cannot be seen or touched. What am I?\no I am a collection of cards, with pictures and numbers. I am used for games and for fortune telling. I am often shuffled and dealt. I can be found in casinos, homes and in the hands of magicians. What am I?\n\n>> The sun in the sunnyside up","CLUES",1);
	}
	cancel_timer=0;
	int time_limit = 300;
	int* time_pointer = &time_limit;
	pthread_t timer_thread;
	int rc = pthread_create(&timer_thread,NULL,countdown_timer,&time_limit);
	if (rc) {
		printf("Error: unable to create thread, %d\n", rc);
		exit(-1);
	}
	if(a==0) {
		char st[7]="PLlAaYy",st1[5]="Aa  O",st2[5]="I  Ll",st3[7]="DdEeCcK",st4[]="#",st5[]="#",st6[]="#",st7[]="#",st8[]="#",st9[]="#",st10[]="#",st11[]="#";
		medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,time_limit);
	}
	if(a==1) {
		char st[7]="MAaKkEe",st1[5]="Aa  U",st2[5]="I  Rr",st3[7]="DdIiNnO",st4[]="#",st5[]="#",st6[]="#",st7[]="#",st8[]="#",st9[]="#",st10[]="#",st11[]="#";
		medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,time_limit);
	}
	if(a==2) {
		char st[7]="BLlOoWw",st1[5]="Aa  E",st2[5]="L  Ee",st3[7]="LlOoCcK",st4[]="#",st5[]="#",st6[]="#",st7[]="#",st8[]="#",st9[]="#",st10[]="#",st11[]="#";
		medium(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,time_limit);
	}
	pthread_join(timer_thread, NULL);
	printf("Your Score: %d", score);
}

void Callhard() {

	system("cls");
	int b=rand()%3;
	if(b==0) {
		MessageBox(0,">>[T---R] I tick and tock, but have no hands. I help you keep track of time, but I'm not a clock. What am I?\n\n>> A U B\n\n>>[T----] I am sometimes hard to find, but always worth the search. I am the opposite of lies, and the foundation of trust. I can be hidden, but always revealed. I am the light that dispels darkness. What am I?\n\n>>[--T--] I am loud and filled with anger, sometimes irrational. I am usually expressed in words, sometimes in actions. I am often used to vent frustration or to express a strongly-held belief. What am I?\n\n>>[R--T-] I can make hearts heavy, and tears fall like rain. I can cause hurt and pain. I can tear families and friendships apart. I am not physical, yet I am all around. What am I\no I am not too wet, not too dry, I am just right. I am important for plants and cakes alike. I can make things fresh or make them rot. I can be caused by rain or by sweating. I am a balance between wet and dry. What am I?","CLUES",1);
	}
	if(b==1) {
		MessageBox(0,">>[T---N] I chug and I whistle, on tracks I glide. Stops I make, but not inside. I carry people, from place to place. I'm long and I'm fast, with a powerful pace. What am I?\n\n>> I am the key to every door, the way to every room. I am the first step to every journey, and the beginning of every adventure. Without me, you're stuck outside, but with me, you're free to roam. What am I?\n\n>>[T----] I am a word that points to something, a reference to what is nearby. I am used to indicate a specific group or set of items. I can be plural or singular, and I come before the noun. I am a way to show possession, a way to indicate 'these things' or 'this one'. What am I?\n\n>>[--R--] I am always ahead of you, but you can never see me. I am always behind you, but you can never catch me. What am I?\n\n>>[-C--R]I bring characters to life, and become someone else. I can be funny, sad, or serious. I am on stage, on screen, or on the radio. I tell stories and make people believe. Without me, a play is just a script. What am I?","CLUES",1);
	}
	if(b==2) {
		MessageBox(0,">>[M---s] I am a group of friends, a close-knit companionship. I am always there for you, a support system. I am the ones you can count on, the ones you can trust. I share laughter and tears, and we create lasting memories. I am the people you call family, but not by blood. What am I?\n\n>>[M----] I am an illusion, a trick of the mind. I am the power of making things happen that are seemingly impossible. I am the art of entertaining, and the source of amazement. I am the embodiment of wonder, and the spark of delight. I can be performed by Magicians, wizards, and sorcerers. What am I?\n\n>>[-R--S] I am a device used to catch something, whether it be an animal or a criminal. I am set up and waiting for an unsuspecting prey. I can be simple or complex, but my purpose remains the same. I can be a physical barrier or an illusion. I am a tool for hunting and protection. What am I?\n\n>>[--S--] I am a necessary evil, without me nothing can be bought. I am always present, but often ignored. I am the price you pay, the value you get. I am not tangible but you can't live without me. What am I?\n\n>>[S--D-] I am tiny, yet I contain a promise of life. Plant me in the ground, give me water and light, and I will grow into something big and strong. What am I?","CLUES",1);
	}

	cancel_timer=0;
	int time_limit = 420;
	int* time_pointer = &time_limit;
	pthread_t timer_thread;
	int rc = pthread_create(&timer_thread,NULL,countdown_timer,&time_limit);
	if (rc) {
		printf("\n\n\n\n\tError: unable to create thread, %d\n", rc);
		exit(-1);
	}
	if(b==0) {

		char st[8]="TIiMmEeR",st1[7]="Rr O Aa",st2[9]="UuNIiOoNn",st3[7]="Tt Ss T",st4[9]="HhAaTEeSs",st5[]="#",st6[]="#",st7[]="#",st8[]="#",st9[]="#",st10[]="#",st11[]="#",st12[]="#",st13[]="#",st14[]="#",st15[]="#",st16[]="#",st17[]="#",st18[]="#",st19[]="#";
		hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19,time_limit);
	}
	if(b==1) {

		char st[8]="TRrAaIiN",st1[7]="Hh C Oo",st2[9]="EeNTtEeRr",st3[7]="Ss Oo T",st4[9]="EeAaRTtHh",st5[]="#",st6[]="#",st7[]="#",st8[]="#",st9[]="#",st10[]="#",st11[]="#",st12[]="#",st13[]="#",st14[]="#",st15[]="#",st16[]="#",st17[]="#",st18[]="#",st19[]="#";
		hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19,time_limit);
	}
	if(b==2)

	{
		char st[8]="MAaTtEeS",st1[8]="Aa R Ee",st2[9]="GgRAaPpEe",st3[7]="Ii Pp D",st4[9]="CcOoSTtSS",st5[]="#",st6[]="#",st7[]="#",st8[]="#",st9[]="#",st10[]="#",st11[]="#",st12[]="#",st13[]="#",st14[]="#",st15[]="#",st16[]="#",st17[]="#",st18[]="#",st19[]="#";
		hard(st,st1,st2,st3,st4,st5,st6,st7,st8,st9,st10,st11,st12,st13,st14,st15,st16,st17,st18,st19,time_limit);
	}
	pthread_join(timer_thread, NULL);
	printf("Your Score: %d", score);
}

//View score function
void Viewscore(int score) {

	if(score==30) {
		system("cls");
		edit_score(score,playername); //Calling this function to edit score and compare with the highest score

		printf("\n\n\n\n\n\n\t*** CONGRATULATION %s YOU HAVE COMPLETED EASY LEVEL ***",playername);
		printf("\n\n\n\n\n\n\t Your Score: %d", score);
		printf("\n\n\n\n\t Press G key to GO TO Another LEVEL!\n\n\n\n\t Press Any other key to return to main menu ");
		if (toupper(getch())=='G') {
			Callmedium();
		} else {
			getch();
			main();
		}
	} else if(score==70) {
		system("cls");
		edit_score(score,playername);
		printf("\n\n\n\n\n\n\t*** CONGRATULATION %s YOU HAVE COMPLETED MEDIUM LEVEL ***",playername);
		printf("\n\n\n\n\n\n\t Your Score: %d", score);
		printf("\n\n\n\n\tPress G key to GO TO Another LEVEL!\n\n\n\n\t Press Any other key to return to main menu ");
		if (toupper(getch())=='G' ) {
			Callhard();
		} else {
			getch();
			main();
		}
	} else if(score==145) {
		system("cls");
		edit_score(score,playername);
		printf("\n\n\n\n\n\n\t*** CONGRATULATION %s YOU HAVE COMPLETED HARD LEVEL ***",playername);
		printf("\n\n\n\n\n\n\t Your Score: %d", score);
		printf("\n\n\n\n\t Press Any key to return to main menu ");
		getch();
		main();
	}


	else {
		system("cls");
		edit_score(score,playername);
		printf("\n\n\n\n\t OH NO LOOKS LIKE YOU COULD NOT CLEAR THIS LEVEL , BETTER LUCK NEXT TIME");
		printf("\n\n\n\n\n\n\t Your Score: %d", score);
		printf("\n\n\n\n\t Press Any key to EXIT");
		getch();
		exit(1);
	}
}
void show_record() {
	//this function prints the highest score
	system("cls");
	char name[20];
	int scr;
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%d",&name,&scr);
	printf("\n\n\t\t*************************************************************");
	printf("\n\n\t\t %s has secured the Highest Score %d",name,scr);
	printf("\n\n\t\t*************************************************************");
	fclose(f);
	getch();
}
void edit_score(int scr, char plnm[20]) {
	//this function stores the highest score obtained by any player in file
	system("cls");
	int sc;
	char nm[20];
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%d",&nm,&sc);
	if (scr>=sc) {
		sc=scr;
		fclose(f);
		f=fopen("score.txt","w");
		fprintf(f,"%s\n%d",plnm,sc);
		fclose(f);
	}
}
