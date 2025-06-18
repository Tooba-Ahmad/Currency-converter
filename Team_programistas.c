#include <stdio.h>

void show_exchange_rate();
float get_exchange_rate(int option);
float convert_pkr_to_foreign(float amount, float rate);
float convert_foreign_to_pkr(float amount, float rate);

int get_valid_int_input(int min, int max);
float get_valid_float_input();

int main() {
    int choice, conversion_type;
    float amount, converted_amount;

    printf("Welcome to Currency Converter\n");

    while (1) {
        printf("\nCURRENCY CONVERTER\n");
        printf("1. Show exchange rate\n2. Convert PKR to foreign currency\n3. Convert foreign to PKR\n4. Exit\n");
        printf("Enter your choice: ");
        choice = get_valid_int_input(1, 4);

        switch (choice) {
        case 1:
            show_exchange_rate();
            break;

        case 2:
            printf("Enter amount in PKR: ");
            amount = get_valid_float_input();

            printf("Select conversion:\n1. USD\n2. EUR\n3. GBP\n4. JPY\n");
            conversion_type = get_valid_int_input(1, 4);

            {
                float rate = get_exchange_rate(conversion_type);
                converted_amount = convert_pkr_to_foreign(amount, rate);
                printf("Converted amount: %.3f\n", converted_amount);
            }
            break;

        case 3:
            printf("Enter amount in foreign currency: ");
            amount = get_valid_float_input();

            printf("Select conversion:\n1. USD\n2. EUR\n3. GBP\n4. JPY\n");
            conversion_type = get_valid_int_input(1, 4);

            {
                float rate = get_exchange_rate(conversion_type);
                converted_amount = convert_foreign_to_pkr(amount, rate);
                printf("Converted amount: %.3f PKR\n", converted_amount);
            }
            break;

        case 4:
            printf("Exiting currency converter thank you for using.\n");
            return 0;

        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}


void show_exchange_rate() {
    printf("Exchange Rates:\n");
    printf("1 USD = 280 PKR\n1 EUR = 300 PKR\n1 GBP = 350 PKR\n1 JPY = 1.96 PKR\n");
}

float get_exchange_rate(int option) {
    switch (option) {
    case 1: return 280.0;
    case 2: return 300.0;
    case 3: return 350.0;
    case 4: return 1.96;
    default: return -1.0;
    }
}

float convert_pkr_to_foreign(float amount, float rate) {
    return amount / rate;
}

float convert_foreign_to_pkr(float amount, float rate) {
    return amount * rate;
}

int get_valid_int_input(int min, int max) {
    int input;
    char ch;
    while (1) {
        if (scanf_s("%d%c", &input, &ch, 1) == 2 && ch == '\n') {
            if (input >= min && input <= max)
                return input;
            else
                printf("Input out of range. Enter a number between %d and %d: ", min, max);
        }
        else {
            printf("Invalid input. Enter a number between %d and %d: ", min, max);
            while (scanf_s("%c", &ch, 1) && ch != '\n');
        }
    }
}

float get_valid_float_input() {
    float input;
    char ch;
    while (1) {
        if (scanf_s("%f%c", &input, &ch, 1) == 2 && ch == '\n') {
            if (input >= 0)
                return input;
            else
                printf("Amount must be non-negative. Enter again: ");
        }
        else {
            printf("Invalid input. Enter a valid number: ");
            while (scanf_s("%c", &ch, 1) && ch != '\n');
        }
    }
}
