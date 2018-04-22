#include <stdio.h>
#include <time.h>


    #define RESET "\033[0m"
    #define GREEN "\033[1;32m"
    #define RED   "\033[1;31m"
    #define CYAN  "\033[1;36m"
    #define GRAY  "\033[2m"
    #define WHITE  "\033[37m"
    #define BLACK "\033[0;30m" 
    // https://habrahabr.ru/post/119436/

void delay()
{
    float milli_seconds = 40000;
    float start_time = clock();
    while (clock() <= start_time + milli_seconds);
}


int main () {
	delay();
    printf("%s\t██████████████████████████████\n" , BLACK); delay();
    printf("\t████████%s" "███%s" "███████████████████\n", RED, BLACK); delay();
    printf("\t█████%s" "██%s" "███%s" "█████%s" "███████████████\n", RED, BLACK, RED, BLACK); delay();
    printf("\t███████%s" "█████████████%s" "██████████%s\n", RED, BLACK, RED); delay();
    printf("\t████%s" "███%s" "█████████████████%s" "██████\n", BLACK,RED, BLACK); delay();
    printf("\t█████%s" "█████%s" "██%s" "███████%s" "██████████%s" "█\n", RED, WHITE, RED, WHITE, BLACK); delay();
    printf("\t█████%s" "█████%s" "██%s" "█████%s" "██%s" "██%s" "██%s" "████%s" "███%s\n", RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK, RED); delay();
    printf("\t██%s" "█%s" "██████%s" "██%s" "█████%s" "██%s" "██%s" "██%s" "██████%s" "██\n", BLACK, RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK); delay();
    printf("\t███%s" "█████%s" "██%s" "██%s" "██%s" "█%s" "██%s" "██%s" "██████%s" "███%s" "██\n", RED, WHITE, RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK); delay();
    printf("\t█%s" "███████%s" "█%s" "██%s" "██%s" "██%s" "█%s" "██%s" "██%s" "████████%s" "██\n",  RED, WHITE, RED, WHITE, RED, WHITE , RED, WHITE, RED, BLACK); delay();
    printf("\t█%s" "██████%s" "██%s" "█%s" "██%s" "██%s" "█%s" "██%s" "██%s" "█████████%s" "██\n", RED, WHITE, RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK); delay();
    printf("\t███%s" "████%s" "█%s" "█%s" "█%s" "█%s" "█%s" "█%s" "█%s" "██%s" "██%s" "██%s" "███%s" "█████%s" "██\n", RED, WHITE, RED, WHITE, RED, WHITE, RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK); delay();
    printf("\t████%s" "███%s" "██%s" "██%s" "███%s" "██%s" "████%s" "███████%s" "███\n", RED, WHITE, RED, WHITE, RED, WHITE, RED, BLACK); delay();
    printf("\t█████%s" "██%s" "█%s" "██████████████████%s" "████\n", RED, WHITE, RED, BLACK); delay();
    printf("\t███████%s" "██████████████████%s" "█████\n", RED, BLACK); delay();
    printf("\t██████████%s" "███████████%s" "█████████%s\n", RED, BLACK, RESET); delay();
    printf ("%s\n _       __\t\t  __   ______\n",RED); delay();     
    printf ("| |     / /___  _________/ /  / ____/___  ____ _\n" ); delay(); 
    printf ("| | /| / / __ \\/ ___/ __  /  / __/ / __ \\/ __ `/\n" ); delay(); 
    printf ("| |/ |/ / /_/ / /  / /_/ /  / /___/ / / / /_/ /\n" ); delay(); 
    printf ("|__/|__/\\____/_/   \\__,_/  /_____/_/ /_/\\__, /\n" ); delay(); 
    printf ("\t\t\t\t       /____/\n%s", RESET);
	main();
  	return 0;
}
