#include "FitnessPerson.hpp"
        
//This function calculates the Soma Coeficient
void FitnessPerson::calculateSomaCoeficent()
{
    if (soma_type == EKTOMORF)
    {
        soma = 1.1;
    }
    else if (soma_type == EKTOMEZOMORF)
    {
        soma = 1.05;
    }
    else if (soma_type == MEZOMORF)
    {
        (soma = 1);
    }
    else if (soma_type == ENDOMEZOMORF)
    {
        soma = 0.95;
    }
    else if (soma_type == ENDOMORF)
    {
        soma = 0.9;
    }
}
//This function calculates the Activity Coeficient
void FitnessPerson::calculateActivityCoeficent()
{
    switch (activity)
    {
    case ACTIVITY_NO:
        activ = 1.2;
        break;
    case ACTIVITY_LIGHT:
        activ = 1.4;
        break;
    case ACTIVITY_MIDDLE:
        (activ = 1.6);
        break;
    case ACTIVITY_INTENSIVE:
        activ = 2;
        break;
    /*default:
        printf("Invalid value\n");
        return 101;*/
    }
}
//This function calculates the Goal Coeficient
void FitnessPerson::calculateGoalCoeficient()
{
    switch (target_goal)
    {
    case WEIGHT_LOOSE:
        G = 0.85;
        //strcpy(GOAL, "Loosing weight");
        break;
    case WEIGHT_MAINTENANCE:
        G = 1;
        //strcpy(GOAL, "Weight maintenance ");
        break;
    case WEIGHT_GAIN:
        (G = 1.2);
        //strcpy(GOAL, "Gain weight");
        break;
    /*default:

        printf("Invalid value\n");
        return 102;*/
    }
}
//This function calculates the Lean Body Mass Coeficient
void FitnessPerson::calculateLeanBodyMassCoeficient()
{
    LBM = weight * (1 - (body_fat / 100));
}
//This function calculates the Basal Metabolism Coeficient
void FitnessPerson::calculateBasalMetabolismCoeficient()
{
    if (gender == Gender::Male)
    {
        BM = 66 + (13.7 * LBM) + (5 * height) - (6.8 * age);
    }
    if (gender == Gender::Female)
    {
        BM = 655 + (9.6 * LBM) + (1.8 * height) - (4.7 * age);
    }
}
//This function calculates the Nutrients Coeficients
void FitnessPerson::calculateNutrientsCoeficients()
        {
            // activity
            A = BM * activ;
            // goal
            B = A * G;
            // somatotyp
            C = B * soma;
            // final calories
            Calories = C;

            // protein
            P = LBM * 3;     // grams
            Protein = P * 4; // calories
            // carbohydrates
            CarbF = Calories - Protein; // remaining calories for carbs and fats
            Ca = CarbF * 0.65;          // calories of carbohydrates
            Carbohydrates = Ca / 4;     // carbohydrates in grams
            // fats
            Fats = Calories - Ca - Protein; // fats in calories
            F = Fats / 9;                   // fats in grams
        }
    

//Constructor sets and calculates everything
/*
 * When the constructor is called it takes the parameters and stores them inside of the class
 * Then it automatically calls the calculation functions to calculate the values
 * The calculated values are stored in variables:
 *     - fitnessPerson.Calories
 *     - fitnessPerson.Protein
 *     - fitnessPerson.Carbohydrates
 *     - fitnessPerson.Fats
 *
 * Note: fitnessPerson is example of name of an instance of this class=FitnessPerson
 *       The varaible definitions are found in the header file in src/backend/FitnessPerson.hpp
 */
FitnessPerson::FitnessPerson(
    int age, int height, 
    double weight, double body_fat, 
    Somatotype soma_type, Activity activity,
    Goal target_goal, std::string name,
    Gender gender)
{
    //Set variables
    this->age = age;
    this->height = height;
    this->weight = weight;
    this->body_fat = body_fat;
    this->soma_type = soma_type;
    this->activity = activity;
    this->target_goal = target_goal;
    this->name = name;
    this->gender = gender;
    //Calculate values
    calculateSomaCoeficent();
    calculateActivityCoeficent();
    calculateGoalCoeficient();
    calculateLeanBodyMassCoeficient();
    calculateBasalMetabolismCoeficient();
    calculateNutrientsCoeficients();
}


