
const fileSelector = document.getElementById('fileSelector');

fileSelector.addEventListener('change', )

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
  };
  
  reader.readAsText(puzzleFile);
}
