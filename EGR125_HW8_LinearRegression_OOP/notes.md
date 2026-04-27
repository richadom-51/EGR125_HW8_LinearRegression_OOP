
# EGR 125 HW 8 - OOP Linear Regression

## Problem Summary

This program uses Object-Oriented Programming to calculate the best-fit line for a set of displacement and force values.

The displacement values are stored as X values, and the force values are stored as Y values. The data is read from a file called `lin_reg.txt`.

The final goal is to calculate the equation of a straight line:

y = mx + b

Where:
- m is the slope
- b is the y-intercept

## Input

The input comes from the file `lin_reg.txt`.

The file contains:
- X values, which represent displacement in meters
- Y values, which represent force in Newtons

The program does not ask the user to type the values manually. It reads the values directly from the file.

## Data Manipulation / Calculations

The program performs these steps:

1. Reads the X and Y values from the file.
2. Stores the values in two vectors.
3. Multiplies the X and Y values together to get XY values.
4. Squares the X values to get X² values.
5. Adds the needed values together.
6. Calculates the slope of the best-fit line.
7. Calculates the y-intercept of the best-fit line.

The slope formula used is:

m = (nΣXY - ΣXΣY) / (nΣX² - (ΣX)²)

The intercept formula used is:

b = (ΣY - mΣX) / n

## Output

The program displays:
- The X values
- The Y values
- The slope
- The y-intercept
- The equation of the best-fit line

## OOP Approach

The program uses a class called `LinearRegression`.

The class contains:
- Private vectors for X and Y values
- Functions for reading the file
- Functions for calculations
- A function for displaying the final result

This makes the program more organized because the data and the functions that work on the data are kept together inside one class.

## Functions Used

### populateVectors()
Reads the data from `lin_reg.txt` and stores the X and Y values in vectors.

### sumVector()
Adds all the values inside a vector.

### multiplyVectors()
Multiplies each X value by its matching Y value and stores the products in a new vector.

### squareVector()
Squares each value in a vector and stores the squared values in a new vector.

### calculateSlope()
Uses the linear regression slope formula to calculate the slope.

### calculateIntercept()
Uses the intercept formula to calculate the y-intercept.

### displayResults()
Displays the original values and the final linear regression equation.



