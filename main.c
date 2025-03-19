#include "item.h"

int main(int argc, char *argv[]) {
	int size = 5;
	Item *item_list = malloc(size * sizeof(Item));
    
	if (!item_list) {
        	printf("Memory allocation failed.\n");
        return 1;
	}

	add_item(item_list, 5.0, "19345", "breakfast", "froot loops cereal", 0);
	add_item(item_list, 3.95, "79542", "dairy", "milk", 1);
	add_item(item_list, 7.50, "20084", "snacks", "cookies", 2);
	add_item(item_list, 10.00, "25981", "beverages", "orange juice", 3);
	add_item(item_list, 2.75, "25980", "produce", "orange", 4);

	print_items(item_list, size);

	double avg_price = average_price(item_list, size);
	printf("\nAverage price of items = %.6f\n", avg_price);

	free_items(item_list, size);

	if (argc == 2) {
        char *sku_to_search = argv[1];
        int found = 0;

	int ct = 0;
        while (ct < size && strcmp(item_list[ct].sku,sku_to_search) != 0) {
            ct++;
        }

        if (ct < size) {
		printf("\nItem found:\n");
            	printf("Item name: %s\n", item_list[ct].name);
            	printf("Item sku: %s\n", item_list[ct].sku);
            	printf("Item category: %s\n", item_list[ct].category);
            	printf("Item price: %.2f\n", item_list[ct].price);
            	found = 1;
        }

        if (!found) {
            printf("\nItem not found.\n");
        }
    }

    return 0;
}
