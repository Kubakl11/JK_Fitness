#include <string>
#include <bits/stdc++.h> 
enum Gender
{
    Male,
    Female
};  

enum Somatotype
{
    EKTOMORF=1,
    EKTOMEZOMORF=2,
    MEZOMORF=3,
    ENDOMEZOMORF=4,
    ENDOMORF=5
};

enum Goal
{
    WEIGHT_LOOSE=1,
    WEIGHT_MAINTENANCE=2,
    WEIGHT_GAIN=3
};
enum Activity
{
    ACTIVITY_NO=1,
    ACTIVITY_LIGHT=2,
    ACTIVITY_MIDDLE=3,
    ACTIVITY_INTENSIVE=4
};
//Class that holds Person nutritional values and calculates them
class FitnessPerson
{
    private:
        void calculateSomaCoeficent();
        void calculateActivityCoeficent();
        void calculateGoalCoeficient();
        void calculateLeanBodyMassCoeficient();
        void calculateBasalMetabolismCoeficient();
        void calculateNutrientsCoeficients();
        //Number-like variables
        double soma, activ, G;
        double A, B, C; //Mysterious variables
        //Even more magic vars
        
        double CarbF, Ca;
    public:
        //Numberish variables
        int age; //Age in years
        int height; //Height in cm
        Activity activity;
        double weight, body_fat;
        double LBM, BM; //Lean body mass and basal metabolism
        double Calories;
        double Protein;
        double Carbohydrates;
        double Fats;
        double P;
        double F;
        //Non number-like variables 
        Gender gender;
        Goal target_goal;
        Somatotype soma_type;
        std::string name;
        FitnessPerson(int age, int height, 
            double weight, double body_fat, 
            Somatotype soma_type, Activity activity,
            Goal target_goal, std::string name,
            Gender gender);
        
};



