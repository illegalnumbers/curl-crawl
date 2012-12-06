
/* Crawler
 *
 * CS3505
 * Compiled by Team Amurica
 * Date: Spring 11
 *
 * Crawls a given webpage and all of the pages it links to
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include <curl/curl.h>
#include <curl/easy.h>
#include "Crawler.h"
#include "Utilities.C"

/*Method which handles all of the crawling events
   *This method will call read() on the first element of the URLs vector
   *It will call parse() after the HTML is read in successfully
   *It will then remove the URL that was just read from the URLs vector
   *
   *Input: none
   *Output: none
   */
  void Crawler::crawl()
  {
    string* HTML = new string("");

    string URLToCrawl = URLs->front(); // Get the first URL in the vector
    currentWebPage = new Webpage(URLToCrawl);

    //Check if the domain contains this Webpage already
    if(!domain->contains(currentWebPage->url))
      {
	if(read(URLToCrawl, HTML)) // Read from the URL into the HTML string variable
	  {
	    parse(HTML);

	    domain->addLink(new Webpage(URLs->front()), currentWebPage); // Now that the link has been processed, add it to the domain
			    
	    cout << currentWebPage->toString() << endl;
	  }
      }

    URLs->pop();
  }

  /*Method to handle reading in the HTML from a given URL
   *
   *Input: A URL as a string, a pointer to a string variable, which will hold the HTML
   *Output: True if the webpage was read successfully, false otherwise
   */
  bool Crawler::read(string URL, string* HTML)
  {
    /* Variable Declaration */
    CURL *curl;	/* That is the connection, see: curl_easy_init */
  
    /* (B) Initilise web query */
    curl = curl_easy_init();
  
    /* (C) Set Options of the web query */
    if (curl)
      {
	curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
	curl_easy_setopt(curl, CURLOPT_HEADER, 0);	 /* Set to 0 and curl ignores the first line */
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 0); /* Don't follow anything else than the particular url requested*/
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);	/* Function Pointer "writer" manages the required buffer size */
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, HTML); /* Data Pointer HTML stores downloaded web content */	
      }
    else
      {
	cout << "Error creating curl object!" << endl;
	return false;
      }
  
    /* (D) Fetch the data */
    if(curl_easy_perform(curl) != 0)
      {
	cout << "Error reading webpage!" << endl;
	curl_easy_cleanup(curl);
	return false;
      }
    else
      {
	/* (E) Close the connection */
	curl_easy_cleanup(curl);
    
	return true;
      }
  }
  
  /*Method to handle parsing the HTML code
   *This method will find <a href> tags, <img> tags, spell check words and count words
   *
   *Input: HTML code as a string
   *Output: none
   */
void Crawler::parse(string* HTML)
  {
    int i = 0;
    while(i < HTML->length())
      {
	if(HTML->at(i) == '<')
	  {
	    i++;
	    if(HTML->at(i) == 'a' && HTML->at(i + 2) == 'h')
	      {
		// cout << "Link found" << endl;
		
		// Get the URL out of the "a href = ..."
		int urlBegin = HTML->find("=", i); // urlBegin will be set to where the URL of the page is

		while (HTML->at(urlBegin) == ' ' || HTML->at(urlBegin) == '=' || HTML->at(urlBegin) == '\"' || HTML->at(urlBegin) == '\'')
			// Search forward until you find a character that isn't a space, =, or quote mark.
			// So, for <a href = "http:/..., urlBegin will be the position of the h.
			urlBegin++;

		// The smallest of the following three integers will be the position of the end of the URL string
		int urlEnd = HTML->find(" ", urlBegin + 1);
		int urlEnd2 = HTML->find(">", urlBegin + 1);
		int urlEnd3 = HTML->find("\"", urlBegin + 1);

		if (urlEnd2 < urlEnd)
			urlEnd = urlEnd2;
		if (urlEnd3 < urlEnd)
			urlEnd = urlEnd3; // urlEnd now contains the smallest.

		string url = HTML->substr(urlBegin, (urlEnd - urlBegin));

		if(url.find("javascript") == string::npos)
		  {
		    bool addSlash = false;
		    
		    if(url.find("http://") == string::npos)
		      {
			if(url.find("www.") == string::npos)
			    addSlash = true;
		      }

		    string tempURL = URLs->front(); // Temporary base url

		    if(addSlash)
		      {
			// Remove the slash at the end of the base url, if it exists
			if(tempURL.at(tempURL.length() - 1) == '/')
			  tempURL = tempURL.substr(0, tempURL.length() - 1);

			if(url.at(0) != '/')
			  url = "/" + url;

			// We must remove the name of the page we're currently on to get the base directory
			if(tempURL.find(".html") != string::npos || tempURL.find(".htm") != string::npos)
			  {
			    int lastSlash = tempURL.find_last_of("/");
			
			    if(lastSlash != string::npos)
			      tempURL = tempURL.substr(0, lastSlash);
			  }

			url = tempURL + url;
		      }

		    string shortenedBaseURL = tempURL.substr(11);
		    
		    if(url.find(shortenedBaseURL) != string::npos)
		      {
			Webpage source = Webpage(tempURL); // Base url, i.e. asdf.com
			Webpage target = Webpage(url); // Link on base url page, i.e. asdf.com/whatisasdf.html

			if(!domain->contains(url))
			    URLs->push(url);

			currentWebPage->links.push_back(url);
		      }
		  }

	      }
	    else if(HTML->at(i) == 'i' && HTML->at(i+1) == 'm' && HTML->at(i+2) == 'g')
	      {
		// <img src = " or <img src=
		// cout << "Image found" << endl;

		int imgBegin = HTML->find("=", i); // imgBegin will be set to where the URL of the image is

		while (HTML->at(imgBegin) == ' ' || HTML->at(imgBegin) == '=' || HTML->at(imgBegin) == '\"' || HTML->at(imgBegin) == '\'')
			// Search forward until you find a character that isn't a space, =, or quote mark.
			// So, for <img src = "image.png..., imgBegin will be the position of the i.
			imgBegin++;

		// The smallest of the following three integers will be the position of the end of the URL string
		int imgEnd = HTML->find(" ", imgBegin + 1);
		int imgEnd2 = HTML->find(">", imgBegin + 1);
		int imgEnd3 = HTML->find("\"", imgBegin + 1);

		if (imgEnd2 < imgEnd)
			imgEnd = imgEnd2;
		if (imgEnd3 < imgEnd)
			imgEnd = imgEnd3; // imgEnd now contains the smallest.

		string image = HTML->substr(imgBegin, (imgEnd - imgBegin));

		bool addSlash = false;
		    
		if(image.find("http://") == string::npos)
		  {
		    if(image.find("www.") == string::npos)
		      addSlash = true;
		  }
		
		string tempURL = URLs->front();

		if(addSlash)
		  {
		    if(tempURL.at(tempURL.length() - 1) == '/')
		      tempURL = tempURL.substr(0, tempURL.length() - 1);

		    // We must remove the name of the page we're currently on to get the base directory
		    if(tempURL.find(".html") != string::npos || tempURL.find(".htm") != string::npos)
		      {
			int lastSlash = tempURL.find_last_of("/");

			if(lastSlash != string::npos)
			  tempURL = tempURL.substr(0, lastSlash);
		      }
		    
		    if(image.at(0) != '/')
		      image = "/" + image;
		    
		    image = tempURL + image;
		  }
		
		string shortenedBaseURL = tempURL.substr(11);
		
		if(image.find(shortenedBaseURL) != string::npos)
		  {
		    //cout << "Image: " << image << endl;
		    // A new thread would start here
		    currentWebPage->imageCount++;
		  }
	      }
	    else if(HTML->at(i) == 's' && HTML->at(i+1) == 'c' && HTML->at(i+2) == 'r' && HTML->at(i+3) == 'i' && HTML->at(i+4) == 'p' && HTML->at(i+5) == 't')
	      {
		i = findMatchingTag(HTML, i + 5, "/script") - 1;
	      }
	    else if(HTML->at(i) == 's' && HTML->at(i+1) == 't' && HTML->at(i+2) == 'y' && HTML->at(i+3) == 'l' && HTML->at(i+4) == 'e')
	      {
		i = findMatchingTag(HTML, i + 4, "/style") - 1;
	      }
	  }
	else if(HTML->at(i) == '>')
	  {
	    i++;

	    string words = "";

	    while(i < HTML->length() && HTML->at(i) != '<')
	      {
		words += HTML->at(i);

		i++;
	      }

	    words = replaceInString(words, "\r", "");
	    words = replaceInString(words, "\n", "");

	    string tempWord = replaceInString(words, " ", "");

	    if(tempWord.compare("") != 0) // Check if there are only spaces in the word
	      {
		//cout << words << endl;
		vector<string> wordsSplit = splitString(words, " ");

		for(int j = 0; j < wordsSplit.size(); j++)
		  {
		    vector<string> strings;
		    if (!dictionary->spelled_correctly(wordsSplit[j]))
		      {
			//cout << wordsSplit[j] << " is spelled incorrectly." << endl;
			currentWebPage->misspelledWordCount++;
		      }
		    else
		      {
			//cout << wordsSplit[j] << " is spelled correctly." << endl;
		      }

		    currentWebPage->wordCount++;
		  }
	      }

	    i--; // Remove one, since one is always added (I think this is necessary)
	  }
	i++;
      }
  }

int main ()
{
  string URL = "http://eng.utah.edu/~tmcknigh/test.html";
  
  cout << "Enter a URL" << endl;

  cin >> URL;

  URL = formatURL(URL);

  queue<string, list<string> >* urlQueue = new queue<string, list<string> >();

  Crawler crawler = Crawler(urlQueue);

  //if(crawler.domain->addLink(new Webpage(""), new Webpage(URL))) TEMPORARILY REMOVED
  urlQueue->push(URL);

  cout << "Creating dictionary.  Please wait..." << endl;
  crawler.dictionary = new Dictionary("dictionary.txt");

  while(urlQueue->size() > 0)
    crawler.crawl();

  
	
  return 0;	
}
