class Solution:

    # returns string 
    def simplifyPath(self, path: str) -> str:
        
        stack = []

        # split string based on "/"
        path_list = path.split("/") # ['', 'home', '', 'root', '..', '']


        for i in path_list:
            if i == '' or i =='.':
                continue
            elif i  == '..':
                # pop top element from stack 
                if len(stack) != 0:
                    stack.pop()
            else:
                stack.append(i)

        # stack will have canonical path
        
        # join stack elements with "/" to get canonical path 
        return "/" + "/".join(stack)
