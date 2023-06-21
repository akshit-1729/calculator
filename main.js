window.addEventListener("click", function (event) {

    let clickedElement = event.target;
    let output = document.getElementById("display")

    let isDiv = clickedElement instanceof HTMLDivElement;
    if (isDiv) {
        if(clickedElement.innerHTML=="=")
        {
            try {
                output.innerHTML=eval(output.innerHTML);
            } catch (error) {
                output.innerHTML="Error " + error;
            }
        }
        else if(clickedElement.innerHTML=="CE")  
        {
            output.innerHTML=""
        }
        else
        {
            output.innerHTML += clickedElement.innerHTML;
        }
    }
});