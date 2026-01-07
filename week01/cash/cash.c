#include <cs50.h>
#include <stdio.h>

int owed;
void quarters();
int main(void)
{
    // Prompt the user for change owed, in cents
    do
    {
        owed = get_int("Owed: ");
    }
    while ( owed <= 0);
    quarters();

}
void quarters()
{
    int quarter = owed / 25;
    owed = owed % 25;

    int dimes = owed / 10;
    owed = owed % 10;

    int nickels = owed / 5;
    owed = owed % 5;

    int pennies = owed ;

    int total = quarter + dimes + nickels + pennies;
    printf("%i\n", total);
}
