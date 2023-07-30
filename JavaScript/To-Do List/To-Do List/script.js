// script.js

// Get references to the elements
const taskForm = document.getElementById("taskForm");
const taskInput = document.getElementById("taskInput");
const taskList = document.getElementById("taskList");

// Function to add a new task to the DOM and local storage
function addTaskToDOM(taskText, dueDate) {
    const taskItem = document.createElement("li");
    taskItem.innerHTML = `
    <input type="checkbox">
    <span>${taskText}</span>
    <input type="date" value="${dueDate}" disabled>
    <button class="deleteBtn">Delete</button>
  `;
    taskList.appendChild(taskItem);
}

// Function to add a new task
function addTask(event) {
    event.preventDefault(); // Prevent form submission

    const taskText = taskInput.value.trim();
    const dueDate = dueDateInput.value; // Get the selected due date
    if (taskText === "") return;

    addTaskToDOM(taskText, dueDate); // Pass the due date to the addTaskToDOM function

    // Save tasks to local storage (including the due date)
    const storedTasks = JSON.parse(localStorage.getItem("tasks")) || [];
    storedTasks.push({ taskText, dueDate });
    localStorage.setItem("tasks", JSON.stringify(storedTasks));

    taskInput.value = "";
    dueDateInput.value = ""; // Reset the due date input
}

// Function to remove a task
function deleteTask(event) {
    if (event.target.classList.contains("deleteBtn")) {
        const taskItem = event.target.parentElement;
        const taskText = taskItem.querySelector("span").textContent;

        // Remove task from local storage
        const storedTasks = JSON.parse(localStorage.getItem("tasks")) || [];
        const updatedTasks = storedTasks.filter(task => task !== taskText);
        localStorage.setItem("tasks", JSON.stringify(updatedTasks));

        taskList.removeChild(taskItem);
    }
}

// Load tasks from local storage on page load
document.addEventListener("DOMContentLoaded", () => {
    const storedTasks = JSON.parse(localStorage.getItem("tasks")) || [];
    storedTasks.forEach(taskText => {
        addTaskToDOM(taskText);
    });
});

// Event listener for the form submission
taskForm.addEventListener("submit", addTask);

// Event Listener for the form submission
taskForm.addEventListener("submit", addTask);

// Event listener for the "Delete" button
taskList.addEventListener("click", deleteTask);