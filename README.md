🛒 Corner Grocer Project
CS-210: Programming Languages
Reflection – Module Eight Journal

Summary

The Corner Grocer project was designed to help a small grocery store analyze which items are purchased most often. The program reads an input file containing a list of grocery items, counts how many times each item appears, and then displays the results through a simple text-based menu. Users can look up how often a specific item was purchased, view all items with their frequencies, or generate a histogram showing item popularity. This project demonstrates core C++ programming concepts such as file input/output, data structures, and building a functional, menu-driven interface that solves a real-world problem.

What I Did Well

One of my main strengths in this project was keeping the code clean and well-organized. Each task—reading the data, counting item frequencies, and displaying results—was separated into its own function, which made the program easier to read, test, and maintain. I also used a C++ map container to efficiently store and access the item counts, which helped the program handle large data files without slowing down. I’m especially proud of how readable the final code is, which makes it easier for future me to understand what’s happening at a glance.

Areas for Improvement

My program already includes several layers of input validation and user feedback, such as checking for missing files, rejecting invalid menu choices, and notifying the user when an item isn’t found. These checks make the program much more reliable and user-friendly. Still, there’s room to improve how the program guides users through errors or unexpected inputs. One area I’d like to enhance is handling multi-word items like “green beans” or “apple juice.” Right now, the program expects items to be single words, so expanding it to correctly parse multi-word entries would make it more realistic and flexible for actual grocery data. This would involve adjusting how the program reads and tokenizes each line from the input file. I could also refine user feedback by tracking invalid attempts and offering helpful suggestions—for example, reminding users that item searches aren’t case-sensitive or suggesting the closest matching item using string comparison. These refinements wouldn’t change the core functionality, but they’d make the program feel smoother, smarter, and more polished—closer to real-world usability standards.

Challenges and How I Overcame Them

The most challenging part of this project was making sure the program read the file correctly and counted each item accurately without missing or duplicating entries. At first, I ran into problems with parsing lines and confirming that every item was being processed. I solved this by breaking the task into smaller steps: first verifying that the file opened successfully, then checking that each line was being read properly, and finally inserting items into the map. Using small test files and print statements helped me debug and confirm that my logic worked as expected.

Transferable Skills

This project helped me strengthen several technical and problem-solving skills that will be useful in both future courses and professional work. I gained hands-on experience with data structures like maps and vectors, modular program design, and file handling in C++. I also got better at debugging and breaking down complex problems into manageable parts. These skills are directly transferable to other programming languages such as Python or Java, and they’re essential for writing clean, efficient, and maintainable code in any environment.

Code Maintainability and Adaptability

I made a conscious effort to design the program so it would be easy to maintain and expand later. I used consistent naming conventions, detailed comments, and avoided hard-coding values. By placing repeated logic into separate functions—like displaying menus or reading data—I made sure that adding new features wouldn’t require rewriting large portions of the code. For example, if the grocery store wanted to add pricing data or track sales by time of day, those features could be implemented with minimal changes to the existing structure. The modular design keeps the code flexible, easy to modify, and ready for future growth.
