#include <stdio.h>
#include <strings.h>

int main()
{

    int a, h;
    float w, bf, soma, activ, G;
    int somatotyp, activity, goal;
    char E, Em, M, Enm, Enf;
    float LBM, BM;
    float A, B, C;
    float Calories;
    float P, Protein;
    float CarbF, Ca, Carbohydrates;
    float Fats, F;
    char name[80];
    char filename[80];
    char gender[10];
    char GOAL[20];

    printf("Welcome in FEL fittnes calculator for calorie intake\n");
    printf("Please write your name:\n");
    scanf(" %79[^\n]", &name);
    printf("Please write your gender:\n");
    scanf("%s", &gender);
    printf("Please write your age:\n");
    scanf("%i", &a);
    printf("Please write your height in cm:\n");
    scanf("%i", &h);
    printf("Please write your weight in kg:\n");
    scanf("%f", &w);
    printf("Please write value of your bodyfat in %%\n");
    scanf("%f", &bf);
    printf("\n");
    printf("Now write type of your somatotyp by the following table\n");

    printf("+-----------+-----------+\n");
    printf("| Somatotyp    | Symbol |\n");
    printf("+-----------------------+\n");
    printf("| Ektomorf     |   1    |\n"); // 1.1
    printf("+-----------------------+\n");
    printf("| Ektomezomorf |   2    |\n"); // 1.05
    printf("+-----------------------+\n");
    printf("| Mezomorf     |   3    |\n"); // 1
    printf("+-----------------------+\n");
    printf("| Endomezomorf |   4    |\n"); // 0.95
    printf("+-----------------------+\n");
    printf("| Endomorf     |   5    |\n"); // 0.9
    printf("+-----------------------+\n");
    printf("Your somatotyp is:\n");
    scanf("%i", &somatotyp);
    if (somatotyp == 1)
    {
        soma = 1.1;
    }
    else if (somatotyp == 2)
    {
        soma = 1.05;
    }
    else if (somatotyp == 3)
    {
        (soma = 1);
    }
    else if (somatotyp == 4)
    {
        soma = 0.95;
    }
    else if (somatotyp == 5)
    {
        soma = 0.9;
    }
    else
    {
        printf("Invalid value\n");
        return 100;
    }

    // printf("%0.1f\n", soma);

    printf("Okey, let's write your activity coeficient by the following table\n");

    printf("+-----------+----------------+\n");
    printf("|      Activity     | Symbol |\n");
    printf("+----------------------------+\n");
    printf("| No activity       |   1    |\n"); // 1.2
    printf("+----------------------------+\n");
    printf("| Light activity    |   2    |\n"); // 1.4
    printf("+----------------------------+\n");
    printf("| Middle activity   |   3    |\n"); // 1.6
    printf("+----------------------------+\n");
    printf("| Intensive activity|   4    |\n"); // 2
    printf("+----------------------------+\n");

    printf("Your activity is:\n");
    scanf("%i", &activity);
    switch (activity)
    {
    case 1:
        activ = 1.2;
        break;
    case 2:
        activ = 1.4;
        break;
    case 3:
        (activ = 1.6);
        break;
    case 4:
        activ = 2;
        break;
    default:
        printf("Invalid value\n");
        return 101;
    }
    printf("And the last one, write your goal coeficient by the following table\n");

    printf("+-----------+-----------------+\n");
    printf("|        Goal        | Symbol |\n");
    printf("+-----------------------------+\n");
    printf("| Loosing weight     |   1    |\n"); // 0.8
    printf("+-----------------------------+\n");
    printf("| Weight maintenance |   2    |\n"); // 1
    printf("+-----------------------------+\n");
    printf("| Gain weight        |   3    |\n"); // 1.2
    printf("+-----------------------------+\n");
    printf("Your goal is:\n");
    scanf("%i", &goal);
    switch (goal)
    {
    case 1:
        G = 0.85;
        strcpy(GOAL, "Loosing weight");
        break;
    case 2:
        G = 1;
        strcpy(GOAL, "Weight maintenance ");
        break;
    case 3:
        (G = 1.2);
        strcpy(GOAL, "Gain weight");
        break;
    default:

        printf("Invalid value\n");
        return 102;
    }

    // lean body mass
    LBM = w * (1 - (bf / 100));
    // basal metabolism
    if (strcasecmp(gender, "Male") == 0)
    {
        BM = 66 + (13.7 * LBM) + (5 * h) - (6.8 * a);
    }
    if ((strcasecmp(gender, "Female") == 0))
    {
        BM = 655 + (9.6 * LBM) + (1.8 * h) - (4.7 * a);
    }

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
    //
    printf("Thank you for information\n");
    // Otevřen9 soubor pro zápis
    sprintf(filename, "%s_calories.txt", name);
    FILE *output_file = fopen(filename, "w");
    //FILE *output_file = fopen("calories_out.txt", "wb");

    // Kontrola, zda se soubor úspěšně otevřel
    if (output_file == NULL)
    {
        fprintf(stderr, "Chyba při otevírání souboru.\n");
        
        return 1;
    }
    fprintf(output_file,"Okey, lets see your results:\n");
    fprintf(output_file,"Lean body mass: %.2f kg\n", LBM);
    fprintf(output_file,"Basal metabolism: %.0f kcal\n", BM);
    fprintf(output_file,"Total calories intake: %.0f kcal\n", Calories+1);
    fprintf(output_file,"Protein: %.0f g\n", P+1);
    fprintf(output_file,"Carbohydrates: %.0f g\n", Carbohydrates+1);
    fprintf(output_file,"Fats: %.0f g\n", F);
    for (int i = 0; i < 2; i++)        //enter
    { fprintf(output_file,"\n");}
    
    fprintf(output_file,"Input data:\n");
    fprintf(output_file,"Name: %s\n", name);
    fprintf(output_file,"Gender: %s\n", gender);
    fprintf(output_file,"Age: %i\n", a);
    fprintf(output_file,"Height: %i cm\n", h);
    fprintf(output_file,"Weight: %.0f kg\n", w);
    fprintf(output_file,"Bodyfat: %.0f %%\n", bf);
    fprintf(output_file,"Goal: %s \n", GOAL);


    fclose(output_file); // Uzavřít soubor po použití
    
    //system("notepad++ calories_out.txt");     dodelat otevreni souboru
    return 0;
}