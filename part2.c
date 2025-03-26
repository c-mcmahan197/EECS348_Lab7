#include <stdio.h>

// Function to convert temperature
float convertTemperature(float value, char from, char to) {
    if (from == to) return value;
    
    if (from == 'C') {
        if (to == 'F') return (value * 9/5) + 32;
        if (to == 'K') return value + 273.15;
    } else if (from == 'F') {
        if (to == 'C') return (value - 32) * 5/9;
        if (to == 'K') return (value - 32) * 5/9 + 273.15;
    } else if (from == 'K') {
        if (to == 'C') return value - 273.15;
        if (to == 'F') return (value - 273.15) * 9/5 + 32;
    }
    return 0;
}

// Function to categorize temperature and provide advisory
void categorizeTemperature(float celsius) {
    if (celsius < 0) {
        printf("Category: Freezing\nAdvisory: Wear warm clothes and stay indoors if possible.\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Category: Cold\nAdvisory: Wear a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Category: Comfortable\nAdvisory: Enjoy the weather.\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Category: Hot\nAdvisory: Stay hydrated and wear light clothes.\n");
    } else {
        printf("Category: Extreme Heat\nAdvisory: Avoid outdoor activities and stay cool.\n");
    }
}

int main() {
    float temperature, convertedTemp;
    char inputScale, targetScale;
    
    // Get user input
    printf("Enter temperature value: ");
    scanf("%f", &temperature);
    
    printf("Enter input scale (C for Celsius, F for Fahrenheit, K for Kelvin): ");
    scanf(" %c", &inputScale);
    
    printf("Enter target scale (C for Celsius, F for Fahrenheit, K for Kelvin): ");
    scanf(" %c", &targetScale);
    
    // Convert temperature
    convertedTemp = convertTemperature(temperature, inputScale, targetScale);
    
    // Display results
    printf("Converted Temperature: %.2f %c\n", convertedTemp, targetScale);
    
    // Categorize and provide advisory in Celsius scale
    float tempInCelsius = convertTemperature(convertedTemp, targetScale, 'C');
    categorizeTemperature(tempInCelsius);
    
    return 0;
}
