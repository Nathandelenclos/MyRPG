/*
** EPITECH PROJECT, 2021
** Swap int
** File description:
** dile for my_swap
*/

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
