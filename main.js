function buttonClicked(clickedElement)
{
    output = document.getElementById("display")

    if(clickedElement.innerHTML=="=")
    {
        try {
            output.innerHTML=eval(output.innerHTML);
        } catch (error) {
            output.innerHTML="Error ";
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