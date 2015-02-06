// Baptiste Fontaine & Julien Sagot -- TP 3
#ifndef _TESTS_H
#define _TESTS_H

/**
 * Simple tests framework for InfoEmb TPs -- Baptiste Fontaine
 **/

/**
 * Define a new tests suite
 *
 * Example:
 *      suite("foobar function") {
 *              // some tests
 *      }
 *
 **/
#define suite(name) printf(name " should:\n");

/**
 * Define a test
 *
 * Example:
 *      it_should("set x to 2", x, 2);
 **/
#define it_should(text, expr, expected) {  \
        printf("- " text ": ");            \
        if ((expr) == (expected)) {        \
                printf("OK\n");            \
        } else {                           \
                printf("FAIL!\n");         \
        }}

#endif
