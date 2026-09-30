#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

#define HOURS_PER_DAY 24
#define INVENTORY_SIZE 10

#define ITEM_EMPTY 0
#define ITEM_WOOD 1
#define ITEM_STONE 2
#define ITEM_SEEDS 3
#define ITEM_WATER 4
#define ITEM_FOOD 5
#define ITEM_TOOL 6
#define ITEM_HOE 7
#define ITEM_APPLE 8
#define ITEM_FLOWER 9

int main() {
    SetConsoleOutputCP(65001);
    int current_day = 1;
    int current_hour = 8;
    int choice = -1;
    int work_hours = 0;
    int i;
    int slot_index, item_id;
    int target_id, cleared_count;
    
    // Инициализация инвентаря
    int inventory[INVENTORY_SIZE] = {
        ITEM_WOOD, ITEM_STONE, ITEM_EMPTY, 
        ITEM_WATER, ITEM_FOOD, ITEM_HOE, 
        ITEM_SEEDS, ITEM_EMPTY, ITEM_APPLE, ITEM_FLOWER
    };
    
    while (1) {
        printf("\n--- Меню ---\n");
        printf("[0] Выход\n");
        printf("[1] Посмотреть на часы\n");
        printf("[2] Промотать время (Поработать)\n");
        printf("[3] Посмотреть инвентарь\n");
        printf("[4] Положить предмет в слот\n");
        printf("[5] Выбросить предмет\n");
        printf("[6] Очистка от мусора (по ID)\n");
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
                printf("\n--- Инвентарь ---\n");
                for (i = 0; i < INVENTORY_SIZE; i++) {
                    printf("Слот %d: [%d] ", i, inventory[i]);
                    switch(inventory[i]) {
                        case ITEM_EMPTY: printf("(Пусто)\n"); break;
                        case ITEM_WOOD: printf("(Дерево)\n"); break;
                        case ITEM_STONE: printf("(Камень)\n"); break;
                        case ITEM_SEEDS: printf("(Семена)\n"); break;
                        case ITEM_WATER: printf("(Вода)\n"); break;
                        case ITEM_FOOD: printf("(Еда)\n"); break;
                        case ITEM_TOOL: printf("(Инструмент)\n"); break;
                        case ITEM_HOE: printf("(Мотыга)\n"); break;
                        case ITEM_APPLE: printf("(Яблоко)\n"); break;
                        case ITEM_FLOWER: printf("(Цветок)\n"); break;
                        default: printf("(Неизвестный предмет)\n"); break;
                    }
                }
                break;
            case 4:
                printf("Введите индекс слота (0-%d): ", INVENTORY_SIZE - 1);
                while (scanf("%d", &slot_index) != 1 || slot_index < 0 || slot_index >= INVENTORY_SIZE) {
                    scanf("%*s");
                    printf("Ошибка ввода. Введите индекс от 0 до %d: ", INVENTORY_SIZE - 1);
                }
                printf("Введите ID предмета: ");
                while (scanf("%d", &item_id) != 1 || item_id < 0) {
                    scanf("%*s");
                    printf("Ошибка ввода. Введите положительное число (ID): ");
                }
                inventory[slot_index] = item_id;
                printf("Предмет с ID %d успешно положен в слот %d.\n", item_id, slot_index);
                break;
            case 5:
                printf("Введите индекс слота для очистки (0-%d): ", INVENTORY_SIZE - 1);
                while (scanf("%d", &slot_index) != 1 || slot_index < 0 || slot_index >= INVENTORY_SIZE) {
                    scanf("%*s");
                    printf("Ошибка ввода. Введите индекс от 0 до %d: ", INVENTORY_SIZE - 1);
                }
                inventory[slot_index] = ITEM_EMPTY;
                printf("Слот %d очищен.\n", slot_index);
                break;
            case 6:
                printf("Введите ID предмета для очистки: ");
                while (scanf("%d", &target_id) != 1) {
                    scanf("%*s");
                    printf("Ошибка ввода. Введите число (ID): ");
                }
                cleared_count = 0;
                for (i = 0; i < INVENTORY_SIZE; i++) {
                    if (inventory[i] == target_id) {
                        inventory[i] = ITEM_EMPTY;
                        cleared_count++;
                    }
                }
                printf("Очищено слотов: %d\n", cleared_count);
                break;
            default:
                printf("Неверный пункт меню. Попробуйте снова.\n");
                break;
        }
    }
    return 0;
}