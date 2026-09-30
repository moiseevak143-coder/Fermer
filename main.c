#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int choice = -1;
    
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
                printf("Функция пока не реализована.\n");
                break;
            case 2:
                printf("Функция пока не реализована.\n");
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