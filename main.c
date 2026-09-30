#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define HOURS_PER_DAY 24

int main() {
    int current_day = 1;
    int current_hour = 8;
    int choice = -1;
    int work_hours = 0;
    
    while (1) {
        printf("\n--- Меню ---\n");
        printf("[0] Выход\n");
        printf("[1] Посмотреть на часы\n");
        printf("[2] Промотать время (Поработать)\n");
        printf("[3] Посмотреть инвентарь\n");
        printf("[4] Положить предмет в слот\n");
        printf("[5] Выбросить предмет\n");
        printf("[6] Выполнить задание по варианту\n");
        printf("Выберите пункт меню: ");
        
        while (scanf("%d", &choice) != 1) {
            scanf("%*s");
            printf("Ошибка ввода. Введите число: ");
        }
        
        switch (choice) {
            case 0:
                printf("Выход из программы.\n");
                return 0;
            case 1:
                printf("Текущее время: День %d, %02d:00\n", current_day, current_hour);
                break;
            case 2:
                printf("Сколько часов вы хотите поработать? ");
                while (scanf("%d", &work_hours) != 1 || work_hours < 0) {
                    scanf("%*s");
                    printf("Ошибка ввода. Введите положительное число часов: ");
                }
                current_hour += work_hours;
                while (current_hour >= HOURS_PER_DAY) {
                    current_hour -= HOURS_PER_DAY;
                    current_day++;
                }
                printf("Вы успешно поработали. Текущее время: День %d, %02d:00\n", current_day, current_hour);
                break;
            case 3:
                printf("Функция пока не реализована.\n");
                break;
            case 4:
                printf("Функция пока не реализована.\n");
                break;
            case 5:
                printf("Функция пока не реализована.\n");
                break;
            case 6:
                printf("Функция пока не реализована.\n");
                break;
            default:
                printf("Неверный пункт меню. Попробуйте снова.\n");
                break;
        }
    }
    return 0;
}