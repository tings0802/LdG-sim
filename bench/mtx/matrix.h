#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#define EQUAL_TH 1e-6

struct matrix {
	size_t row;
	size_t col;
	double* elements;
};

typedef struct matrix matrix;

matrix* new_matrix(size_t row, size_t col);
void free_matrix(void* self);

size_t get_row(const matrix* self);
size_t get_col(const matrix* self);
double get_item(const matrix* self, size_t row, size_t col);
void set_item(matrix* self, size_t row, size_t col, double value);
bool equal(const matrix* m, const matrix* n);
bool symmetric(const matrix* self);
bool traceless(const matrix* self);

matrix* trans(const matrix* m);
matrix* add_mm(const matrix* m, const matrix* n);
matrix* add_ms(const matrix* m, double s);
matrix* add_sm(double s, const matrix* m);
matrix* mul_mm(const matrix* m, const matrix* n);
matrix* mul_ms(const matrix* m, double s);
matrix* mul_sm(double s, const matrix* m);
matrix* dot_mm(const matrix* m, const matrix* n);

#endif