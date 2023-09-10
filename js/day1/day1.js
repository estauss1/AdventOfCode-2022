
const fileSelector = document.getElementById('fileSelector');
const partOne = document.getElementById('partOne');
const partTwo = document.getElementById('partTwo');

if(fileSelector == null){
  console.log("fileSelector was null.\n");
}else {
  console.log("fileSelector was fine. Wtf is going on lil bro.\n");
}

fileSelector.addEventListener('change',handlePuzzleInput);

function handlePuzzleInput(event) {
  const puzzleFile = event.target.files[0];
  const reader = new FileReader();
  
  reader.onload = function (evt) {
    const fileContentStr = evt.target.result;
    const caloriesArr = fileContentStr.split("\n");

    let i = 0;
    let invenTotal = 0;
    let invenItem = 0;
    const totals = [];
    while( i < caloriesArr.length){
      while(caloriesArr[i] != "" && i < caloriesArr.length){
        invenItem = parseInt(caloriesArr[i], 10);
        invenTotal += invenItem;
        ++i;
      }
      ++i;
      totals.push(invenTotal);
      invenTotal = 0;
    }
    //find max from totals (part 1 answer) 
    let max = totals[0];
    let iOfMax = 0;
    for(let i = 1; i < totals.length; ++i){
      if(totals[i] > max){ 
        max = totals[i];
        iOfMax = i;
      }
    }
    partOne.textContent = `Part 1 Answer: The elf inventory containing the greatest
      number of calories contained ${max} calories.`;

    //part 2 
    let topThree = max;
    //remove current max then find next max 
    let tmp = totals[iOfMax];
    totals[iOfMax] = totals[totals.length - 1];
    totals[totals.length - 1] = tmp;
    totals.pop();

    let maxTwo = totals[0];
    let maxThree = totals[1];
    let gThanTwo = false;
    let gThanThree = false;
    for(let i = 2; i < totals.length; ++i){
      gThanTwo = (totals[i] > maxTwo) ? true : false;
      gThanThree = (totals[i] > maxThree) ? true : false;
      //if greater than both current maxes, assign to smaller max
      if(gThanTwo && gThanThree){
        if(maxTwo <= maxThree)
          maxTwo = totals[i];
        else
          maxThree = totals[i];
      }
      else if(gThanTwo && !gThanThree)
        maxTwo = totals[i];
      else if(gThanThree && !gThanTwo)
        maxThree = totals[i];
      //reset flags
      gThanTwo = false;
      gThanThree = false;
    }
    topThree = topThree + maxTwo + maxThree;
    //add part 2 answer to DOM 
    partTwo.textContent = `Part 2 Answer: The top three elf inventories with the most 
      calories has a combined calorie count of: ${topThree}`;
  };
  
  reader.readAsText(puzzleFile);
}
