List<String> ReturnOneTempRecipe(String name, String ingr[]){
  List<String> data = new List<String>();
  data.Add(name);
  int number_of_stored_values_in_myarray = sizeof(ingr)/sizeof(String);
  for(int i = 0; i < number_of_stored_values_in_myarray;i++){
    data.Add(ingr[i]);
  }
  return data;
}

List<List<String>> ReturnTempRecipeData(){
  List<List<String>> data = new List<List<String>>();
  String ingridents1[] = {"Vodka","Rum", "Cider"};
  
  data.Add(ReturnOneTempRecipe("Recipe1", ingridents1));
  data.Add(ReturnOneTempRecipe("Recipe1", ingridents1));
  data.Add(ReturnOneTempRecipe("Recipe1", ingridents1));
  return data;
}
