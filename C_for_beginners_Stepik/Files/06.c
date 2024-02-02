#include <stdio.h>

typedef struct {
    int yy;   // год
    char mm;  // месяц
    char dd;  // день
} Data;

typedef struct {
    int yy;       // год
    char season;  // время года (зима - 0, весна - 1, лето - 2, осень - 3)
    int day;      // день от начала текущего времени года
} Season;

Data getData() {
    Data input;
    printf("getData()");
    int m, d;
    scanf("%d-%d-%d", &input.yy, &m, &d);
    input.mm = m;
    input.dd = d;
    return input;
}
void printData(Data Data) {
    printf("printData()");
    printf("%04d-%02d-%02d\n", Data.yy, (int)Data.mm, (int)Data.dd);
}
Season convToSeas(Data Data) {
    printf("convToSeas(Data Data)");
    Season res;
    res.yy = Data.yy;
    switch (Data.mm) {
        case 12:  // зима
            res.day = Data.dd;
            res.season = 0;
            break;
        case 1:
            res.day = Data.dd + 31;
            res.season = 0;
            break;
        case 2:
            res.day = Data.dd + 62;
            res.season = 0;
            break;
        case 3:  // весна
            res.day = Data.dd;
            res.season = 1;
            break;
        case 4:
            res.day = Data.dd + 31;
            res.season = 1;
            break;
        case 5:
            res.day = Data.dd + 61;
            res.season = 1;
            break;
        case 6:  // лето
            res.day = Data.dd;
            res.season = 2;
            break;
        case 7:
            res.day = Data.dd + 30;
            res.season = 2;
            break;
        case 8:
            res.day = Data.dd + 61;
            res.season = 2;
            break;
        case 9:  // осень
            res.day = Data.dd;
            res.season = 3;
            break;
        case 10:
            res.day = Data.dd + 30;
            res.season = 3;
            break;
        case 11:
            res.day = Data.dd + 61;
            res.season = 3;
            break;
    }
    return res;
}

void printSeas(Season season) {
    printf("printSeas(Season season)");
    printf("%04d-%02d-%02d\n", season.yy, (int)season.season, (int)season.day);
}

int main() {
    Data dat;
    Season seas;
    dat = getData();
    printData(dat);
    seas = convToSeas(dat);
    printSeas(seas);

    return 0;
}