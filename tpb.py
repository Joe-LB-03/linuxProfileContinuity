from requests import get
from urllib.parse import quote_plus
from bs4 import BeautifulSoup as bs
from sys import argv
from subprocess import call


def get_magnet(search):
    """Gets magnet link from given search term
    
    Makes a request to The Pirate Bay.
    Uses BeautifulSoup to parse the Response and gets the first magnet link
    
    Parameters:
    search term to find
    
    Returns:
    magnet link
    """

    tpb = get('https://tpb.one/search/'+ quote_plus(search) +'/0/99/200')
    html = bs(tpb.text, 'html.parser')

    # get first link with 'magnet' term
    for link in html.find_all('a'):
        href = link.get('href')
        if 'magnet' in href:
            return href

    return None


if __name__ == '__main__':
    
    search = ' '.join('TheFrenchDispatch')
    magnet = get_magnet(search)
    # call for transmission
    if magnet is not None:
        call(["transmission-gtk", magnet])
    else:
        print("No magnets found for", search)