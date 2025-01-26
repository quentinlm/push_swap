/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quclaque <quclaque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:32:35 by quclaque          #+#    #+#             */
/*   Updated: 2025/01/26 15:02:33 by quclaque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int is_sorted(t_stack *a) {
    t_list *current = a->top;
    int prev;
    if (current == NULL)
        return 1;
    prev = current->value;
    current = current->next;
    while (current != NULL) {
        if (prev > current->value)
            return 0;
        prev = current->value;
        current = current->next;
    }
    return 1;
}

static int get_max(t_stack *a) {
    t_list *current = a->top;
    int max = current->value;
    while (current) {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return max;
}

static void sort_three(t_stack *a) {
    int max = get_max(a);
    if (a->top->value == max)
        ra(a);
    else if (a->top->next->value == max)
        rra(a);
    if (a->top->value > a->top->next->value)
        sa(a);
}

static int find_min_index(t_stack *a) {
    t_list *current = a->top;
    int min = current->value;
    int index = 0;
    int i = 0;
    while (current) {
        if (current->value < min) {
            min = current->value;
            index = i;
        }
        current = current->next;
        i++;
    }
    return index;
}

static void move_smallest_to_b(t_stack *a, t_stack *b) {
    int index = find_min_index(a);
    int size = a->size;
    if (index <= size / 2) {
        for (int i = 0; i < index; i++)
            ra(a);
    } else {
        for (int i = 0; i < size - index; i++)
            rra(a);
    }
    pb(a, b);
}

static void sort_medium(t_stack *a, t_stack *b) {
    int push_count = a->size - 3;
    for (int i = 0; i < push_count; i++)
        move_smallest_to_b(a, b);
    sort_three(a);
    for (int i = 0; i < push_count; i++)
        pa(a, b);
}

static void ft_sort_int_tab(int *tab, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

static int find_index(int *arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

static void normalize(t_stack *a) {
    int size = a->size;
    int *arr = malloc(size * sizeof(int));
    t_list *current = a->top;
    for (int i = 0; current; i++) {
        arr[i] = current->value;
        current = current->next;
    }
    ft_sort_int_tab(arr, size);
    current = a->top;
    while (current) {
        int index = find_index(arr, size, current->value);
        current->value = index;
        current = current->next;
    }
    free(arr);
}

static void radix_sort(t_stack *a, t_stack *b) {
    int max_bit = 0;
    int max_num = a->size - 1;
    while ((max_num >> max_bit) != 0)
        max_bit++;
    for (int bit = 0; bit < max_bit; bit++) {
        int original_size = a->size;
        for (int i = 0; i < original_size; i++) {
            int value = a->top->value;
            if ((value >> bit) & 1)
                ra(a);
            else
                pb(a, b);
        }
        while (b->size > 0)
            pa(a, b);
    }
}

void sort(t_stack *a, t_stack *b) {
    if (is_sorted(a))
        return;
    int size = a->size;
    if (size == 2)
        sa(a);
    else if (size == 3)
        sort_three(a);
    else if (size <= 5)
        sort_medium(a, b);
    else {
        normalize(a);
        radix_sort(a, b);
    }
}