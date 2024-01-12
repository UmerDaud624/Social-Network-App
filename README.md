It is a console based social network application and have the following functionality...
Each User has a unique ID and name. He may have other users in his friend list, having 10 friends at max. 
He has a list of pages which he has liked (10 likedpages at max),  each Page has a unique ID, title.
Each Post has a unique ID, description/text, no of likes, list of people who have liked it and shared date.
Activity may be a part of the Post, having a type and a value against this type.
A MemoryisaPost having pointer to original post.
A commentis posted by a specific user or page.
All data about users, pages, posts and comments that are to be read from, are in attached text files.
1- SetCurrent User
 a. Ask user about his ID and set him as current user of application. Now everything that we
 see in the system will be view of this user.
2- View Home of CurrentUser
 a. Display posts of all friends shared in last 24 hours.
 b. Display posts of all his liked pages shared in last 24 hours.
3- Like apost
 a. Askuser about ID of post and like it. A post can be liked by 10 users at max.
4- Viewthelist of People who liked a post
 a. TakePost ID from user and display list of people who have liked it
5- CommentonaPost
 a. Takepost ID and comment from the user and add this comment in the post
6- ViewaPost
 a. Takepost ID and Display the post with its Comments
7- ShareaMemory
 a. Takepost ID, text from user and share it
8- ViewUser’s Timeline
 a. Display User Name
 b. Display user’s posts in his timeline
9- ViewFriend List
 a. TakeIDof auser and display his friends list
10- View Page
 a. TakePage ID and display all its post
All function calls are hardcoded(command prompts).
