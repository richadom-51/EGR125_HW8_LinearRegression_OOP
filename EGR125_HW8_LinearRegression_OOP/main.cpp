#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class LinearRegression {
private:
    vector<double> xValues;
    vector<double> yValues;
    double slope;
    double intercept;
    int n;
    
public:
    // Constructor
    LinearRegression() : slope(0), intercept(0), n(0) {}
    
    // Read data from file and populate vectors
    void populateVectors(string filename) {
        ifstream infile(filename);
        
        // Error handling for file open
        if (!infile.is_open()) {
            cout << "Error: Could not open file " << filename << endl;
            return;
        }
        
        string label;
        double value;
        
        // Read X values
        infile >> label;  // Read "X(m)"
        while (infile >> value) {
            xValues.push_back(value);
        }
        
        // Clear fail state from hitting "Y(N)"
        infile.clear();
        
        // Read Y values
        infile >> label;  // Read "Y(N)"
        while (infile >> value) {
            yValues.push_back(value);
        }
        
        infile.close();
        
        // Validate data: check sizes match and vectors are not empty
        if (xValues.size() == 0 || yValues.size() == 0) {
            cout << "Error: No data read from file" << endl;
            return;
        }
        
        if (xValues.size() != yValues.size()) {
            cout << "Error: X and Y vectors have different sizes" << endl;
            return;
        }
        
        n = xValues.size();
    }
    
    // Sum all elements in a vector
    double sumVector(vector<double> values) {
        double sum = 0;
        for (int i = 0; i < values.size(); i++) {
            sum += values[i];
        }
        return sum;
    }
    
    // Multiply corresponding X and Y values to create a new vector
    vector<double> multiplyVectors() {
        vector<double> result;
        for (int i = 0; i < xValues.size(); i++) {
            result.push_back(xValues[i] * yValues[i]);
        }
        return result;
    }
    
    // Square each element in a vector to create a new vector
    vector<double> squareVector(vector<double> values) {
        vector<double> result;
        for (int i = 0; i < values.size(); i++) {
            result.push_back(values[i] * values[i]);
        }
        return result;
    }
    
    // Calculate slope using least-squares formula
    void calculateSlope() {
        double sumX = sumVector(xValues);
        double sumY = sumVector(yValues);
        
        // Multiply X and Y values, then sum the products
        vector<double> xTimesY = multiplyVectors();
        double sumXY = sumVector(xTimesY);
        
        // Square X values, then sum the squares
        vector<double> xSquared = squareVector(xValues);
        double sumXSquared = sumVector(xSquared);
        
        // Formula: slope = (n * sumXY - sumX * sumY) / (n * sumXSquared - sumX * sumX)
        double numerator = n * sumXY - sumX * sumY;
        double denominator = n * sumXSquared - sumX * sumX;
        
        slope = numerator / denominator;
    }
    
    // Calculate y-intercept using least-squares formula
    void calculateIntercept() {
        double sumX = sumVector(xValues);
        double sumY = sumVector(yValues);
        
        // Formula: intercept = (sumY - slope * sumX) / n
        intercept = (sumY - slope * sumX) / n;
    }
    
    // Display input data and calculated results
    void displayResults() {
        cout << "\n========== LINEAR REGRESSION RESULTS ==========" << endl;
        
        cout << "\nX Values (m): ";
        for (int i = 0; i < xValues.size(); i++) {
            cout << xValues[i] << " ";
        }
        
        cout << "\nY Values (N): ";
        for (int i = 0; i < yValues.size(); i++) {
            cout << yValues[i] << " ";
        }
        
        cout << "\n\nCalculated Parameters:" << endl;
        cout << "Slope (m) = " << fixed << setprecision(4) << slope << endl;
        cout << "Intercept (b) = " << fixed << setprecision(4) << intercept << endl;
        
        cout << "\nBest-fit Line Equation:" << endl;
        cout << "y = " << slope << "x + " << intercept << endl;
        cout << "===============================================\n" << endl;
    }
};

int main() {
    LinearRegression regression;
    
    // Step 1: Read data from file
    regression.populateVectors("lin_reg.txt");
    
    // Step 2: Calculate slope
    regression.calculateSlope();
    
    // Step 3: Calculate intercept
    regression.calculateIntercept();
    
    // Step 4: Display results
    regression.displayResults();
    
    return 0;
}
