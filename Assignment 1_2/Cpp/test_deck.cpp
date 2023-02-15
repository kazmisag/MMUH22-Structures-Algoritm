#include "deck.h"

#include "gtest/gtest.h"

TEST(Card, init)
{
    SUCCEED();
}

TEST(Deck, init)
{
    SUCCEED();
}

// Testing insert function in deck
TEST(Deck, insert)
{
    Deck deck;              /* Deck class object */
    vector<Card> card_list; /* empty vector*/

    // Create cards
    Card c1 = Card(1, Suit::Hearts);
    Card c2 = Card(3, Suit::Clubs);
    Card c3 = Card(5, Suit::Spades);
    Card c4 = Card(3, Suit::Spades);
    Card c5 = Card(5, Suit::Spades);

    deck.insert(card_list, c1);
    EXPECT_EQ(c1.rank, card_list[0].rank); // test card 1 rank at index 0

    deck.insert(card_list, c2); // insert card 2 in the deck

    deck.insert(card_list, c3); // insert card 3 in the deck

    EXPECT_EQ(c2.rank, card_list[1].rank); // test card rank at index 1
    ASSERT_EQ(3, card_list.size());        // test size, the deck has 3 cards}

    EXPECT_EQ(c3.rank, card_list[0].rank); // Test if c3 is on top of the deck
    ASSERT_EQ(3, card_list.size());        // test size
    EXPECT_EQ(c5.rank, card_list[0].rank); // test if c1 is still at 0 index
    // ASSERT_EQ(c3.rank, deck.take().rank); // Test if you can get card 3 from the deck
}

TEST(Deck, shuffle_size_take)
{
    Deck deck;
    /**
     * Testing shuffle function
     */
    // Add more cards to the deck and then shuffle
    deck.shuffle();             // create a new shuffle the deck in random
    EXPECT_EQ(52, deck.size()); // Expect 52 shuffled deck

    // deck.sort();                                 // Sort the deck
    // std::cout<<deck; // Test print deck

    Card test_card = Card(1, Suit::Clubs); // create a 1D card to check it

    // EXPECT_EQ(test_card.rank, deck.take().rank); // Test if sorted deck has 1D

    Card card_taken = deck.take(); // Take a card out
    ASSERT_EQ(51, deck.size());    // Test if the deck has two less cards in the deck

    std::cout << card_taken << std::endl; // Test print the taken card
    /**
   Testing put() function
    */
    deck.put(card_taken);       // Put the card back in the deck
    ASSERT_EQ(52, deck.size()); // Test if the deck size is 52 again

    // Print out the shufflled deck
    // std::cout << deck<<std::endl; // Test print deck

    // vector<Card> test_cards; // A test card deck
    // Deck *deckPtr;

    // while (deckPtr->size() > 0)
    // {
    //     Deck::insert(test_cards, deckPtr->take());
    // }
    // // Print out the deck
    // for (int i = 0; i < deck.size(); i++)
    // {

    //     std::cout << test_cards[i]; // Test print deck
    // }
}