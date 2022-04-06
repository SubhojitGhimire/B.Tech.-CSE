Instructions on how to install or use python libraries/dependencies or pip used in some of this project, as well as on proxy protected university's internet:  
(FOR WINDOWS USERS ONLY)

To install packages using pip, Go to Terminal or CMD and enter following set proxy commands before sueing pip install:  
set http_proxy=172.16.199.40:8080  
set https_proxy=172.16.199.40:8080  

This proxy IP address and Port can vary accoring to your proxy setup, or for admin connections, the proxy IP is 172.16.199.20  
So take care of these little variations.  

DO NOT close the terminal/cmd where you ran the set proxy commands. Write your pip install code after setting proxy. For example,  
pip install numpy  
pip install networkx  

In lab 4 and and lab 7, community package is used. This is not the same as community package inside networkx package (that we will see for LFR benchmark resolve).  
To have this separate community package installed, run the following:  
pip install python-louvain  

Lastly, for LFR_Benchmark graph (used in exp 2 and 6), the latest networkx package is missing community_generators.py file. So manually make a .py file named "community_generators.py" and copy paste the python code included in this SNA Lab folder.  
Make sure the name is "community_generators.py". Also, make sure you are making this .py file in the correct location.   
Location is: Python Folder -> Lib -> site-packages -> networkx -> algorithms -> community -> make the community_generators.py file here. 
For example, my location looks something like this: .\Python\Python310\Lib\site-packages\networkx\algorithms\community  
