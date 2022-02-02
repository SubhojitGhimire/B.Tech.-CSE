import urllib.request
import io 
import zipfile
import matplotlib.pyplot as plt 
import networkx as nx 

url="http://www-personal.umich.edu/~mejn/netdata/football.zip"
sock=urllib.request.urlopen(url)
s=io.BytesIO(sock.read())
sock.close()
zf=zipfile.ZipFile(s)
txt=zf.read("football.txt").decode()
gml=zf.read("football.gml").decode()
gml=gml.split("\n")[1:]

club1=nx.parse_gml(gml)
club2=nx.karate_club_graph()

#degree centrality
centrality1_club1=nx.degree_centrality(club1)
print('\n',centrality1_club1)
plt.figure(figsize=(15,15))
nx.draw_networkx(club1, with_labels=True)
plt.show()

centrality1_club2=nx.degree_centrality(club2)
print('\n',centrality1_club2)
plt.figure(figsize=(15,15))
nx.draw_networkx(club2, with_labels=True)
plt.show()

#betweenness centrality
centrality2_club1=nx.betweenness_centrality(club1,normalized=True,endpoints=False)
print ('\n',centrality2_club1)
plt.figure(figsize=(15,15))
nx.draw_networkx(club1, with_labels=True)
plt.show()

centrality2_club2=nx.betweenness_centrality(club2,normalized=True,endpoints=False)
print ('\n',centrality2_club2)
plt.figure(figsize=(15,15))
nx.draw_networkx(club2, with_labels=True)
plt.show()

#eigenvector centrality
centrality3_club1=nx.eigenvector_centrality(club1)
print ('\n',centrality3_club1)
plt.figure(figsize=(15,15))
nx.draw_networkx(club1, with_labels=True)
plt.show()

centrality3_club2=nx.eigenvector_centrality(club2)
print ('\n',centrality3_club2)
plt.figure(figsize=(15,15))
nx.draw_networkx(club2, with_labels=True)
plt.show()