/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/ArrayList.h"
#include "../inc/Employee.h"



int main(void)
{
        startTesting(1);//listo al_newarraylist
        startTesting(2);//listo all add
        startTesting(3);//listo al delete arraylist
        startTesting(4);//listo all len
        startTesting(5);//listo al get
        startTesting(6);//listo  al contanis
        startTesting(7);//listo al set
        startTesting(8);//listo al remove
        startTesting(9);//listo al clear
        startTesting(10);//Listo al clone
        startTesting(11);//listo el push
        startTesting(12);//listo  al indexof
        startTesting(13);//listo al empty
        startTesting(14);//listo el pop
        startTesting(15);//listo subList
        startTesting(16);//listo al containsall
        startTesting(17);//listo al_sort

    return 0;
}





