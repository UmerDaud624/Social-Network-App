It is a console based social network application and have the following functionality...<br>
Each User has a unique ID and name. He may have other users in his friend list, having 10 friends at max.<br> 
He has a list of pages which he has liked (10 likedpages at max),  each Page has a unique ID, title.<br>
Each Post has a unique ID, description/text, no of likes, list of people who have liked it and shared date.<br>
Activity may be a part of the Post, having a type and a value against this type.<br>
A MemoryisaPost having pointer to original post.<br>
A commentis posted by a specific user or page.<br>
All data about users, pages, posts and comments that are to be read from, are in attached text files.<br>
1- Set Current User<br>
 a. Ask user about his ID and set him as current user of application. Now everything that we<br>
 see in the system will be view of this user.<br>
2- View Home of CurrentUser<br>
 a. Display posts of all friends shared in last 24 hours.<br>
 b. Display posts of all his liked pages shared in last 24 hours.<br>
3- Like a post<br>
 a. Ask user about ID of post and like it. A post can be liked by 10 users at max.<br>
4- View the list of People who liked a post<br>
 a. Take Post ID from user and display list of people who have liked it<br>
5- Comment on a Post<br>
 a. Take post ID and comment from the user and add this comment in the post<br>
6- View a Post<br>
 a. Take post ID and Display the post with its Comments<br>
7- Share a Memory<br>
 a. Take post ID, text from user and share it<br>
8- View User’s Timeline<br>
 a. Display User Name<br>
 b. Display user’s posts in his timeline<br>
9- View Friend List<br>
 a. Take ID of auser and display his friends list<br>
10- View Page<br>
 a. Take Page ID and display all its post<br>
All function calls are hardcoded(command prompts).<br>
