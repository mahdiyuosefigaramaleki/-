#include <stdio.h>
#include <stdlib.h>
int isleap(int year){
    int leapyears[71] = {1210,1214,1218,1222,1226,1230,1234,
                         1238,1243,1247,1251,1255,1259,1263,
                         1267,1271,1276,1280,1284,1288,1292,
                         1296,1300,1304,1309,1313,1317,1321,
                         1325,1329,1333,1337,1342,1346,1350,
                         1354,1358,1362,1366,1370,1375,1379,
                         1383,1387,1391,1395,1399,1403,1408,
                         1412,1416,1420,1424,1428,1432,1436,
                         1441,1445,1449,1453,1457,1461,1465,
                         1469,1474,1478,1482,1486,1490,1494,
                         1498};
    
    for (int i = 0 ; i < 71 ; i++){
        if (year == leapyears[i]){
            return 1;
        }
    }
    return 0;
}
int distance(int year,int month,int day){
    int leapyears[71] = {1210,1214,1218,1222,1226,1230,1234,
                         1238,1243,1247,1251,1255,1259,1263,
                         1267,1271,1276,1280,1284,1288,1292,
                         1296,1300,1304,1309,1313,1317,1321,
                         1325,1329,1333,1337,1342,1346,1350,
                         1354,1358,1362,1366,1370,1375,1379,
                         1383,1387,1391,1395,1399,1403,1408,
                         1412,1416,1420,1424,1428,1432,1436,
                         1441,1445,1449,1453,1457,1461,1465,
                         1469,1474,1478,1482,1486,1490,1494,
                         1498};
    int sum = 0;
    sum+=(year - 1206);
    sum*=365;
    if (month <= 7){
        sum+=((month - 1) * 31);
    }
    else {
        sum+=186;
        sum+=((month - 7) * 30);
    }
    for (int i = 0 ; i < 71 ; i++){
        if (year <= leapyears[i]){
            sum+=i;
            break;
        }
    }
    sum+=day;
    sum--;
    return sum;
}



void printer(int year,int month,int day){
    int rem = distance(year,month,day)%7;
    int leap = isleap(year); 
    int i,j = 0;
    int k;
    if (month <= 6){
        k = 31;
    }
    else if (month >= 7 && month != 12){
        k = 30;
    }
    else if (month == 12 && leap){
        k = 30;
    }
    else{
        k = 29;
    }
    printf("ST SN MN TU WD TH FR\n");
    if (rem == 0){
        j = 5;
        printf("               ");
        for (i = 1 ; i <= k ; i++){
            if (j == 6){
                printf("\033[1;31m");
            }
            printf("%d ",i);
            printf("\033[0m");
            if (i < 10){
                printf(" ");
            }
            j++;
            if (j == 7){
                printf("\n");
                j = 0;
            }
        }
    }
    else if (rem == 1){
        j = 6;
        printf("                  ");
        for (i = 1 ; i <= k ; i++){
            if (j == 6){
                printf("\033[1;31m");
            }
            printf("%d ",i);
            printf("\033[0m");
            if (i < 10){
                printf(" ");
            }
            j++;
            if (j == 7){
                printf("\n");
                j = 0;
            }
        }
    }
    else if (rem == 2){
        for (i = 1 ; i <= k ; i++){
            if (j == 6){
                printf("\033[1;31m");
            }
            printf("%d ",i);
            printf("\033[0m");
            if (i < 10){
                printf(" ");
            }
            j++;
            if (j == 7){
                printf("\n");
                j = 0;
            }
        }
    }
    else if (rem == 3){
        j = 1;
        printf("   ");
        for (i = 1 ; i <= k ; i++){
            if (j == 6){
                printf("\033[1;31m");
            }
            printf("%d ",i);
            printf("\033[0m");
            if (i < 10){
                printf(" ");
            }
            j++;
            if (j == 7){
                printf("\n");
                j = 0;
            }
        }
    }
    else if (rem == 4){
        printf("      ");
        j = 2;
        for (i = 1 ; i <= k ; i++){
            if (j == 6){
                printf("\033[1;31m");
            }
            printf("%d ",i);
            printf("\033[0m");
            if (i < 10){
                printf(" ");
            }
            j++;
            if (j == 7){
                printf("\n");
                j = 0;
            }
        }
    }
    else if (rem == 5){
        printf("          ");
        j = 3;
        for (i = 1 ; i <= k ; i++){
            if (j == 6){
                printf("\033[1;31m");
            }
            printf("%d ",i);
            printf("\033[0m");
            if (i < 10){
                printf(" ");
            }
            j++;
            if (j == 7){
                printf("\n");
                j = 0;
            }
        }
    }
    else if (rem == 6){
        printf("            ");
        j = 4;
        for (i = 1 ; i <= k ; i++){
            if (j == 6){
                printf("\033[1;31m");
            }
            printf("%d ",i);
            printf("\033[0m");
            if (i < 10){
                printf(" ");
            }
            j++;
            if (j == 7){
                printf("\n");
                j = 0;
            }
        }
    }
    printf("\n");
    for (int i = 0 ; i < 20 ; i++){
        printf("- ");
    }
    printf("\n");
}
void calendar(){
    int year,month;
    system("cls");
    while (1){
        printf("[0] Back to menu!\n");
        for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
        printf("Enter year : ");
        scanf("%d",&year);
        if (year == 0){
            system("cls");
            printf("Back to menu!");
            printf("\n");
            return;
        }
        else if (year > 1498 || year < 1206){
            while (1){
                system("cls");
                printf("[0] Back to menu!\nInvalid input!\n");
                for (int i = 0 ; i < 20 ; i++){
                printf("- ");
                }
                printf("\n");
                printf("Enter year : ");
                scanf("%d",&year);
                if (year == 0){
                system("cls");
                printf("Back to menu!");
                printf("\n");
                return;
                }
                else if (year > 1498 || year < 1206){
                    continue;
                }
                else {
                    break;
                }
            }
        }
        printf("Enter month : ");
        scanf("%d",&month);
        if (month == 0){
            system("cls");
            printf("Back to menu!");
            printf("\n");
            return;
        }
        else if (month > 12 || month < 1){
            while (1){
                system("cls");
                printf("[0] Back to menu!\nInvalid input!\n");
                for (int i = 0 ; i < 20 ; i++){
                printf("- ");
                }
                printf("\n");
                printf("Enter year : %d ",year);
                printf("\nEnter month : ");
                scanf("%d",&month);
                if (month == 0){
                system("cls");
                printf("Back to menu!");
                printf("\n");
                return;
                }
                else if (month > 12 || month < 1){
                    continue;
                }
                else {
                    break;
                }
            }
        }
        system("cls");
        if (month == 1){
            printf("     Farvardin\n");
        }
        else if (month == 2){
            printf("    Ordibehesht\n");
        }
        else if (month == 3){
            printf("      khordad\n");
        }
        else if (month == 4){
            printf("        Tir\n");
        }
        else if (month == 5){
            printf("      Mordad\n");
        }
        else if (month == 6){
            printf("     shahrivar\n");
        }
        else if (month == 7){
            printf("        Mehr\n");
        }
        else if (month == 8){
            printf("        Aban\n");
        }
        else if (month == 9){
            printf("        Azar\n");
        }
        else if (month == 10){
            printf("        Dey\n");
        }
        else if (month == 11){
            printf("      Bahman\n");
        }
        else {
            printf("       Esfand\n");
        }
        printer(year,month,1);
    }
}



void age(){
    int format;
    int year,month,day;
    system("cls");
    while (1){ 
    }
}

int main(){
    system("cls");
    printf("Welcome!\n");
    int n;
    while (1){
        for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
        printf("[0] Quit\n");
        printf("[1] Calendar\n");
        printf("[2] Age\n");
        printf("[3] convertion\n");
        for (int i = 0 ; i < 20 ; i++){
            printf("- ");
        }
        printf("\n");
        printf("Select option : ");
        scanf("%d",&n);
        if (n == 0){
            system("cls");
            printf("Bye!");
            break;
        }
        else if(n == 1){
            calendar();
        }
        else if(n == 2){
            age();
        }
        else if(n == 3){

        }
        else {
            system("cls");
            printf("Invalid input!\n");
        }
    }
}